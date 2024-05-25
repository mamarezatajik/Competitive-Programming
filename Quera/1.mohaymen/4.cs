// using System;
// using System.Collections.Generic;
// using static System.Console;
// using static System.Math;
// using System.Linq;
// using System.Text;
// using System.Linq.Expressions;


// public class Additive {

//     private int _key {get; set;}
//     public Additive(int key) => _key = key;

//     public string Encrypt(string text) {
//         text = text.Trim();
//         text = text.ToUpper();
//         int len = text.Length;

//         StringBuilder result = new StringBuilder();
//         for (int i = 0; i < len; i++) {
//             if (text[i] == ' ')
//                 result.Append(' ');
//             else
//                 result.Append((char)(((text[i] - 'A' + _key) % 26) + 'A'));
//         }

//         return result.ToString().ToUpper();
//     }
// }

// public class Multiplicative {
//     private int _key {get; set;}

//     public Multiplicative(int key) => _key = key;

//     public string Encrypt(string text) {
//         text = text.Trim();
//         text = text.ToUpper();
//         int len = text.Length;

//         StringBuilder result = new StringBuilder();
//         for (int i = 0; i < len; i++) {
//             if (text[i] == ' ')
//                 result.Append(' ');
//             else
//                 result.Append((char)((text[i] - 'A') * _key % 26 + 'A'));
//         }

//         return result.ToString().ToUpper();
//     }
// }

// public class Affine {
//     private int _a, _b;

//     public Affine (int a, int b) {
//         _a = a;
//         _b = b;
//     }

//     public string Encrypt(string text) {
//         text = text.Trim();
//         text = text.ToUpper();
//         int len = text.Length;

//         StringBuilder result = new StringBuilder();
//         for (int i = 0; i < len; i++) {
//             if (text[i] == ' ')
//                 result.Append(' ');
//             else
//                 result.Append((char)((_a * (text[i] - 'A') + _b) % 26 + 'A'));
//         }

//         return result.ToString().ToUpper();
//     }
// }

// public class Mapping {
//     private string _mapping;

//     public Mapping (string mapping) => _mapping = mapping;

//     public string Encrypt(string text) {
//         text = text.Trim();
//         text = text.ToUpper();
//         _mapping = _mapping.ToUpper();
//         int len = text.Length;

//         StringBuilder result = new StringBuilder();
//         for (int i = 0; i < len; i++) {
//             if (text[i] == ' ')
//                 result.Append(' ');
//             else
//                 result.Append((char)_mapping[text[i] - 'A']);
//         }

//         return result.ToString().ToUpper();
//     }
// }



// public class Program {
//     public static void Main() {
//         int n = int.Parse(ReadLine());
//         StringBuilder tmp, command = new StringBuilder();
//         int a = -1, b = -1, key = -1;
//         string input = "", cipherType = "", mapping = "", text = "";

//         for (int i = 0; i < n; i++) {
//             input = ReadLine();
//             cipherType = input.Split()[0];

//             int j = input.IndexOf(' ') + 1;
//             int len = input.Length;
//             for (; j < len; j++) {
//                 if (input[j] == '-') {
//                     command = new StringBuilder();
//                     while (j < len && input[j] != ' ')
//                         command.Append(input[j++]);
//                 }
//                 else {
//                     tmp = new StringBuilder();
//                     if (command.ToString() == "-text") {
//                         j += 1;

//                         while (j < len && input[j] != '"')
//                             tmp.Append(input[j++]);
//                         // string[] words = tmp.ToString().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
//                         // text = string.Join(" ", words);
//                         text = tmp.ToString();
//                         j++;
//                     }

//                     else if (command.ToString() == "-a") {
//                         while (j < len && input[j] != ' ')
//                             tmp.Append(input[j++]);

//                         a = int.Parse(tmp.ToString());
//                     }

//                     else if (command.ToString() == "-b") {
//                         while (j < len && input[j] != ' ')
//                             tmp.Append(input[j++]);

//                         b = int.Parse(tmp.ToString());
//                     }

//                     else if (command.ToString() == "-key") {
//                         while (j < len && input[j] != ' ')
//                             tmp.Append(input[j++]);

//                         key = int.Parse(tmp.ToString());
//                     }

//                     else {                   // mapping
//                         j += 1;

//                         while (j < len && input[j] != '"') {
//                             if (input[j] == ' ')
//                                 j++;
//                             else
//                                 tmp.Append(input[j++]);
//                         }
//                         mapping = tmp.ToString();
//                     }
//                 }
//             }

//             if (cipherType == "additive-cipher") {
//                 Additive cipher = new Additive(key);
//                 WriteLine(cipher.Encrypt(text));
//             }
//             else if (cipherType == "multiplicative-cipher") {
//                 Multiplicative cipher = new Multiplicative(key);
//                 WriteLine(cipher.Encrypt(text));
//             } 
//             else if (cipherType == "affine-cipher") {
//                 Affine cipher = new Affine(a, b);
//                 WriteLine(cipher.Encrypt(text));
//             }
//             else {
//                 Mapping cipher = new Mapping(mapping);
//                 WriteLine(cipher.Encrypt(text));
//             }
//         }
//     }
// }