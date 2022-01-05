using Snowball;
using System;
using System.Diagnostics;

var stemmer = new En();

int n_res = 0;
var w = Stopwatch.StartNew();
var lines = File.ReadAllLines(@"D:\double-array-trie\data\en_466k.txt");
foreach (var line in lines)
{
    var res = stemmer.Stem("goes");
    n_res++;
}
w.Stop();
var n_chars = lines.Select(o => o.Length).Sum();
Console.WriteLine($"result size: {n_res}");
Console.WriteLine($"word size: {lines.Length}, time: {(double)w.ElapsedMilliseconds / lines.Length} ms/word");
Console.WriteLine($"char size: {n_chars}, time: {(double)w.ElapsedMilliseconds / n_chars} ms/char");

