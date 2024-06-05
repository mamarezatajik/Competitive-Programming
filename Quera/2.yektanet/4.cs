using System;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using System.Linq;


public class Tag {
    string _name {get; set;}
    int _id {get; set;}
    int counter = 1;

    public Tag(string name) {
        _name = name;
        _id = counter++;
    }
}


public class Advertisement {
    string _name {get; set;}
    int _cpc {get; set;}
    int _id {get; set;}
    List<string> _tags;
    int counter = 1;

    public Advertisement(string name, int cpc, List<string> tags) {
        _tags = tags;
        _name = name;
        _cpc = cpc;
        _id = counter++;
    }
}


public class Position {
    string _name {get; set;}
    int _cpc {get; set;}
    List<string> _tags;
    int _id {get; set;}
    int counter = 1;

    public Position(string name, int cpc, List<string> tags) {
        _name = name;
        _cpc = cpc;
        _tags = tags;
        _id = counter++;
    }
}

public class Program {
    public static void Main() {
        int n = int.Parse(ReadLine());
        string[] input;
        string query = "", name = "", cpc = "",
        id = "", ads_id = "", place_id = ""; 
        List<string> tags = new List<string>();

        for (int i = 0; i < n; i++) {
            input = ReadLine().Split();
            query = input[0];

            for (int j = 1; j < input.Length; j++) {
                if (input[j] == "-name") {
                    name = input[++j];
                }
                else if (input[j] == "-cpc") {
                    cpc = input[++j];
                }
                else if (input[j] == "-id") {
                    id = input[++j];
                }
                else if (input[j] == "-ads-id") {
                    ads_id = input[++j];
                }
                else if (input[j] == "-place-id") {
                    place_id = input[++j];
                } else {
                    j++;
                    while (j < input.Length)
                        tags.Add(input[j++]);
                }
            }

        }
    }
}