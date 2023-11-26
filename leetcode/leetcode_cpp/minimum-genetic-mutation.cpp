/*
https://leetcode.com/problems/minimum-genetic-mutation

Solution1. BSF
time: o(n) n*8 + n
space: o(n) n(q) + n(hash)

1. store bank into hashmap with minMutation count
2. queue add startGene
3. loop queue, BSF.
4. pop from queue and mutate char on from begin to end.
5. check mutated string is bank, if it is exit loop
6. check minMutation in hashMap, if minMutation is smaller or equal exit loop
7. save new minMutation
8. if mutation is not the endGene push into queue


*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> m;
        for (const auto& str: bank)
            m[str] = 0;
        if (!m.count(endGene)) return -1;

        queue<string> q;
        q.push(startGene);

        while (!q.empty()) {
            int qn = q.size();
            for (int i=0; i<qn; ++i) {
                auto str = q.front();
                q.pop();

                int cnt = m.count(str) ? m[str] : 0;
                cnt++;

                for (int j=0; j<str.size(); ++j) {
                    for (auto c : "ACGT") {
                        if (str[j] == c) 
                            continue;
                        auto str_mutate = str;
                        str_mutate[j] = c;
                        if (str_mutate == endGene) return cnt;

                        if (!m.count(str_mutate)) continue;                        
                        if (m[str_mutate] != 0 && cnt >= m[str_mutate]) continue;
                        
                        m[str_mutate] = cnt;
                        q.push(str_mutate);
                    }
                }
            }
        }
        return -1;
    }
};