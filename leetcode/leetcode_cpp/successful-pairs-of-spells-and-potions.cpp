/*
https://leetcode.com/problems/successful-pairs-of-spells-and-potions

1. brute force
time: n^m

2. sort and binary search
time: o(nlogn + mlogn)
space: o(1)
*/
class Solution {
public:
    vector<int> successfulPairs_1(vector<int>& spells, vector<int>& potions, long long& success) {
        for (int i=0; i<spells.size(); ++i) {
            int spell = spells[i];
            int cnt = 0;
            for (int j=0; j<potions.size(); ++j) {
                if ((1LL * spell * potions[j]) >= success) cnt += 1;
            }
            spells[i] = cnt;
        }
        return spells;
    }

    vector<int> successfulPairs_2(vector<int>& spells, vector<int>& potions, long long& success) {
        sort(potions.begin(), potions.end());
        for (int i=0; i<spells.size(); ++i) {
            int spell = spells[i];
            int idx = upper_bound(potions.begin(), potions.end(), success, [&spell](long long success, int& potion) {
                return success <= (1LL * spell * potion);
            }) - potions.begin();
            spells[i] = potions.size() - idx;
        }
        return spells;
    }

    vector<int> successfulPairs_2_2(vector<int>& spells, vector<int>& potions, long long& success) {
        sort(potions.begin(), potions.end());
        for (int i=0; i<spells.size(); ++i) {
            int spell = spells[i];
            int l = 0, r = potions.size()-1;
            while (l<=r) {
                int m = (r - l) / 2 + l;
                if (success <= 1LL * potions[m] * spell)
                    r = m - 1;
                else
                    l = m + 1;
            }
            spells[i] = potions.size() - r - 1;
        }
        return spells;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        return successfulPairs_2_2(spells, potions, success);
    }
};