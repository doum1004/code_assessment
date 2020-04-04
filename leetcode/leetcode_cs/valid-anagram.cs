// https://leetcode.com/problems/valid-anagram/

public class Solution {
    public bool IsAnagram_sort(ref string s, ref string t) {
        if (s.Length != t.Length) return false;
        var sArray = s.ToCharArray();
        var tArray = t.ToCharArray();
        Array.Sort(sArray);
        Array.Sort(tArray);
        for (int i=0; i<s.Length; ++i) {
            if (sArray[i] != tArray[i]) return false;
        }
        return true;
    }
    
    public bool IsAnagram_hash(ref string s, ref string t) {
        var d = new Dictionary<char,int>();
        foreach (var c in s) {
            if (!d.ContainsKey(c)) d.Add(c, 0);
            d[c]++;
        }
        foreach (var c in t) {
            if (!d.ContainsKey(c)) return false;
            d[c]--;
        }
        
        return true;
    }
    
    public bool IsAnagram(string s, string t) {
        return IsAnagram_sort(ref s,ref t);
    }
}