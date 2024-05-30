using System;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using System.Linq;


public class Program {
    static Dictionary<string, List<int>> invertedIndex;
    static List<HashSet<string>> docs;
    public static void Main() {
        string[] tmp = {"a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "if", "in", "into", "is", "it", "no", "not", "of", "on", "or", "such", "that", "the", "their", "then", "there", "these", "they", "this", "to", "was", "will", "with" };
        HashSet<string> badWords = new HashSet<string>();

        foreach (string s in tmp)
            badWords.Add(s);

        invertedIndex = new Dictionary<string, List<int>>();

        int n = int.Parse(ReadLine());
        string[] documents = new string[n];
        docs = new List<HashSet<string>>();


        for (int i = 0; i < n; i++) {
            docs.Add(new HashSet<string>());
            string document = ReadLine();
            document = new string(document.Where(c => char.IsLetter(c) || c == ' ').ToArray()).ToLower();
            List<string> words = document.ToString().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
            foreach (string badWord in badWords)
                if (words.Contains(badWord))
                    words.Remove(badWord);

            foreach (string word in words) {
                if (!invertedIndex.ContainsKey(word))
                    invertedIndex.Add(word, new List<int>());
                invertedIndex[word].Add(i + 1);
            }

            docs[i] = words.ToHashSet();
            document = string.Join(" ", words);
            documents[i] = document;
        }


        int q = int.Parse(ReadLine());
        JsonObjectCreator joc = new JsonObjectCreator();

        string query;
        for (int i = 0; i < q; i++) {
            query = ReadLine();
            var json = joc.CreateFromPath(query);
            var res = Solve(n, json);
            if (res.Count == 0)
                WriteLine("NO RESULT");
            else {
                foreach (var item in res)
                    Write($"{item} ");
                WriteLine();
            }
        }
    }

    private static List<int> Solve(int n, Dictionary<string, object> json) {
        List<int> res = new List<int>();
        if (json.Keys.First() == "and") {
            // List<int> res = new List<int>();
            List<HashSet<int>> res3 = new List<HashSet<int>>();
            foreach (var item in (List<object>)json["and"]) {
                var res2 = Solve(n, (Dictionary<string, object>)item);
                res3.Add(res2.ToHashSet());
            }

            for (int i = 1; i < 1501; i++) {
                bool ok = true;
                foreach (var item in res3) {
                    if (!item.Contains(i))
                        ok = false;
                }
                if (ok)
                    res.Add(i);
            }
            // return res;
        }
        else if (json.Keys.First() == "or") {
            HashSet<int> res3 = new HashSet<int>();
            foreach (var item in (List<object>)json["or"]) {
                var res2 = Solve(n, (Dictionary<string, object>)item);
                foreach (var x in res2)
                {
                    res3.Add(x);
                }
            }
            res = res3.ToList();
            // return res;
        }
        else if (json.Keys.First() == "not") {
            HashSet<int> hs = new HashSet<int>();
            foreach (var item in (Dictionary<string, object>)json["not"]) {
                string key = item.Key;
                object value = item.Value;
                Dictionary<string, object> dic = new Dictionary<string, object>();
                dic.Add(key, value);
                List<int> res2 = Solve(n, dic);
                foreach (var item2 in res2)
                    hs.Add(item2);
            }

            for (int i = 1; i <= n; i++) {
                if (!hs.Contains(i))
                    res.Add(i);
            }
        }
        else if (json.Keys.First() == "match") {
            if (invertedIndex.ContainsKey(json["match"].ToString()))
                return invertedIndex[json["match"].ToString()];
            return new List<int>();
        } 
        else if (json.Keys.First() == "any") {
            HashSet<int> res2 = new HashSet<int>();

            foreach (var str in (List<object>)json["any"]) {
                if (invertedIndex.ContainsKey(str.ToString()))
                    foreach (var index in invertedIndex[str.ToString()])
                        res2.Add(index);
            }
            

            // List<int> res = new List<int>();
            res = res2.ToList();
            res.Sort();

            // return res;
        } 
        else {                   //    "all"
            for (int i = 0; i < n; i++) {
                bool ok = true;
                foreach (var str in (List<object>)json["all"])
                    if (!docs[i].Contains(str))
                        ok = false;
                if (ok) {
                    res.Add(i + 1);
                }
            }
        }

        res.Sort();

        if (json.ContainsKey("size")) {
            WriteLine(json["size"]);
            for (int i = 0; i < res.Count; i++) {
                if (res[i] > int.Parse(json["size"].ToString())) {
                    res.RemoveRange(i, res.Count - i);
                    break;
                }
            }
        }


        return res;
    }
}

public class JsonObjectCreator
{
    private void SetValue(Dictionary<string, object> json, string path, string value)
    {
        var keys = path.Split('.');
        for (var i = 0; i < keys.Length; i++)
        {
            var key = keys[i];
            if (key.Contains('[') && key.Contains(']'))
            {
                var keyPart = key.Substring(0, key.IndexOf('['));
                var index = int.Parse(key.Substring(key.IndexOf('[') + 1, key.IndexOf(']') - key.IndexOf('[') - 1));
                if (!json.ContainsKey(keyPart))
                {
                    json[keyPart] = new List<object>();
                }

                var list = (List<object>)json[keyPart];
                while (list.Count <= index)
                {
                    list.Add(new Dictionary<string, object>());
                }

                if (i == keys.Length - 1)
                {
                    list[index] = value;
                }
                else
                {
                    json = (Dictionary<string, object>)list[index];
                }
            }
            else
            {
                if (i == keys.Length - 1)
                {
                    json[key] = value;
                }
                else
                {
                    if (!json.ContainsKey(key))
                    {
                        json[key] = new Dictionary<string, object>();
                    }

                    json = (Dictionary<string, object>)json[key];
                }
            }
        }
    }

    public Dictionary<string, object> CreateFromPath(string jsonPath)
    {
        var json = new Dictionary<string, object>();
        var paths = jsonPath.Split(',');
        foreach (var path in paths)
        {
            var parts = path.Split('=');
            var keyPath = parts[0];
            var value = parts[1];
            SetValue(json, keyPath, value);
        }

        return json;
    }
} 