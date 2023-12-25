/*
https://leetcode.com/problems/substring-with-concatenation-of-all-words

Solution1. sliding window with hash map
time: o(L*N) s.size() * N(all words)
space: o(n)
https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/969070/approach-using-hashmap-and-sliding-window-concepts-in-c-easy-understandable-code/?envType=study-plan-v2&envId=top-interview-150

*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n1 = words.size();
        int n2 = words[0].size();
        int totalWords = n1*n2;
        int n3 = s.size();
        if (!n1 || !n2 || !n3) return {};

        unordered_map<string, int> wordMap, tempMap;
        for (auto& word : words) wordMap[word] += 1;
        
        vector<int> res;
        for (int i=0; i<n3-totalWords+1; ++i) {
            for (int j=i; j<i+totalWords; j+=n2) {
                string subs = s.substr(j, n2);
                if (wordMap.count(subs)) tempMap[subs] += 1;
                else break;
            }
            if (tempMap == wordMap) res.push_back(i);
            tempMap.clear();
        }
        return res;
    }
};