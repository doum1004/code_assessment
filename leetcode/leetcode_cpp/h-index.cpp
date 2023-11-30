/*
https://leetcode.com/problems/h-index

Solution1. brute force
time: o(n^2)
space: o(1)

Solution2. sort
time: o(nlogn)
space: o(1)

1. sort
2. iterate from end and find value in index(n-h-1) is at leasst h or not

Solution3. hash table
time: o(n)
space: o(n)

*/
class Solution {
public:
    int hIndex_1(vector<int>& citations) {
        int n = citations.size();
        if (!citations.size()) return 0;
        int res = 0;
        for (int i=n; i>=0; --i) {
            int count = 0;
            for (auto num : citations) {
                if (num >= i)
                    count++;
                if (count == i) {
                    return i;
                }
            }
        }
        return 0;
    }

    int hIndex_2(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i=n; i>=1; --i) {
            if (citations[n-i] >= i)
                return i;
        }
        return 0;
    }

    int hIndex_3(vector<int>& citations) {
        int n = citations.size();

        vector<int> hash(n+1, 0);
        for (auto num : citations) {
            if (num >= n)
                hash[n]++;
            else
                hash[num]++;
        }

        int count = 0;
        for (int i=n; i>=1; --i)
        {
            count += hash[i];
            if (count >= i)
                return i;
        }

        return 0;
    }


    int hIndex(vector<int>& citations) {
        return hIndex_3(citations);
    }
};