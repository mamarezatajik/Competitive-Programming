using System;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using System.Linq;


public class Tag {
    public string _name {get; set;}
    public int _id {get; set;}
    static int counter = 1;

    public Tag(string name) {
        _name = name;
        _id = counter++;
    }
}


public class Advertisement {
    public string _name {get; set;}
    public int _cpc {get; set;}
    public int _id {get; set;}
    public List<string> _tags;
    static int counter = 1;

    public Advertisement(string name, int cpc, List<string> tags) {
        _tags = tags;
        _name = name;
        _cpc = cpc;
        _id = counter++;
    }
}


public class Place {
    public string _name {get; set;}
    public int _cpc {get; set;}
    public List<string> _tags;
    public int _id {get; set;}
    static int counter = 1;

    public Place(string name, int cpc, List<string> tags) {
        _name = name;
        _cpc = cpc;
        _tags = tags;
        _id = counter++;
    }
}

public class Program {
    public static void Main() {
        Dictionary<string, int> tagNames = new Dictionary<string, int>();
        Dictionary<int, Tag> allTags = new Dictionary<int, Tag>();

        Dictionary<string, int> adNames = new Dictionary<string, int>();
        Dictionary<int, Advertisement> allAdvertisements = new Dictionary<int, Advertisement>();

        Dictionary<string, int> placeNames = new Dictionary<string, int>();
        Dictionary<int, Place> allPlaces = new Dictionary<int, Place>();



        int n = int.Parse(ReadLine());
        string[] input;
        string query = "", name = "", cpc = "",
        id = "", ads_id = "", place_id = ""; 
        List<string> tags = new List<string>();

        for (int i = 0; i < n; i++) {
            tags = new List<string>();
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

            if (query == "ADD-TAG") {
                if (tagNames.ContainsKey(name)) {
                    WriteLine("Error: Tag already exists");
                } else {
                    Tag newTag = new Tag(name);
                    tagNames.Add(name, newTag._id);
                    allTags.Add(newTag._id, newTag);
                    WriteLine($"Done: Tag id is {newTag._id}");
                }
            }
            else if (query == "ADD-ADS") {
                if (adNames.ContainsKey(name))
                    WriteLine("Error: Ad already exists");
                else if (tags.Count == 0)
                    WriteLine("Error: Tag not found");
                else {
                    Advertisement newAd = new Advertisement(name, int.Parse(cpc), tags);
                    adNames.Add(name, newAd._id);
                    allAdvertisements.Add(newAd._id, newAd);
                    WriteLine($"Done: Ads id is {newAd._id}");
                }
            }
            else if (query == "ADD-PLACE") {
                if (placeNames.ContainsKey(name))
                    WriteLine("Error: Place already exists");
                else if (tags.Count == 0)
                    WriteLine("Error: Tag not found");
                else {
                    Place newPlace = new Place(name, int.Parse(cpc), tags);
                    placeNames.Add(name, newPlace._id);
                    allPlaces.Add(newPlace._id, newPlace);
                    WriteLine($"Done: Place id is {newPlace._id}");
                }
            } 
            else if (query == "TAG-LIST") {
                Write("TAGs: ");
                foreach (string tagName in tagNames.Keys)
                    Write($"{tagName} ");
                WriteLine();
            } 
            else if (query == "ADS-LIST") {
                Write("ADSs: ");
                foreach (string adName in adNames.Keys)
                    Write($"{adName} ");
                WriteLine();
            } 
            else if (query == "PLACE-LIST") {
                Write("PLACEs: ");
                foreach (string placeName in placeNames.Keys)
                    Write($"{placeName} ");
                WriteLine();
            }
            else if (query == "SUGGEST-ADS") {
                if (!allPlaces.ContainsKey(int.Parse(id)))
                    WriteLine("Error: Place not found");
                else {
                    Write("SUGGEST-ADS: ");
                    Place newPlace = allPlaces[int.Parse(id)];
                    List<Tuple<int, int>> ans = new List<Tuple<int, int>>();
    
                    foreach (var ad in allAdvertisements.Values) {
                        int matched = 0, unMatched = 0;
                        for (int k = 0; k < ad._tags.Count; k++) {
                            if (newPlace._tags.Contains(ad._tags[k]))
                                matched++;
                            else
                                unMatched++;
                        }
                        ans.Add(Tuple.Create(ad._id, (matched - unMatched) / (Max(1, (ad._cpc - newPlace._cpc)))));
                    }

                    ans.Sort((a, b) => b.Item1 == a.Item1 ? a.Item2.CompareTo(b.Item2) : b.Item1.CompareTo(a.Item1));
                    foreach (var item in ans)
                    {
                        Write($"{item.Item2} ");
                    }
                    WriteLine();
                }
            } 
            else if (query == "SUGGEST-PLACE") {
                if (!allAdvertisements.ContainsKey(int.Parse(id)))
                    WriteLine("Error: Ads not found");
                else {
                    Write("SUGGEST-PLACE: ");
                    Advertisement newAd = allAdvertisements[int.Parse(id)];
                    List<Tuple<int, int>> ans = new List<Tuple<int, int>>();
    
                    foreach (var place in allPlaces.Values) {
                        int matched = 0, unMatched = 0;
                        for (int k = 0; k < place._tags.Count; k++) {
                            if (newAd._tags.Contains(place._tags[k]))
                                matched++;
                            else
                                unMatched++;
                        }
                        ans.Add(Tuple.Create(place._id, ((matched - unMatched) / (Max(1, (place._cpc - newAd._cpc))))));
                    }


                    ans.Sort((a, b) => b.Item1 == a.Item1 ? a.Item2.CompareTo(b.Item2) : b.Item1.CompareTo(a.Item1));
                    foreach (var item in ans)
                    {
                        Write($"{item.Item2} ");
                    }
                    WriteLine();
                }
            }
            else {     // MATCH
                if (!allAdvertisements.ContainsKey(int.Parse(ads_id)))
                    WriteLine("Error: Ads not found");
                else if (!allPlaces.ContainsKey(int.Parse(place_id)))
                    WriteLine("Error: Place not found");
                else {
                    WriteLine($"Done: {ads_id} matched to {place_id}");
                    adNames.Remove(allAdvertisements[int.Parse(ads_id)]._name);
                    placeNames.Remove(allPlaces[int.Parse(place_id)]._name);
                    allAdvertisements.Remove(int.Parse(ads_id));
                    allPlaces.Remove(int.Parse(place_id));
                }
            }
        }
    }
}