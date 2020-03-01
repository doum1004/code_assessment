#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>

using namespace std;

/**
https://leetcode.com/problems/compare-version-numbers/

return (version1 > version2) ? 1 : (version1 < version2) ? -1 : 0

// Solution1. get vectors of both and compare
// time: o(n+m)
// space: o(n+m)

// Solution2. two pointers to iterate each till '.' or end and compare
// time: o(n+m)
// space: o(1)

// Solution3. istringstream
// time: o(n+m)
// space: o(1)

*/

class Solution {
public:
    vector<int> getVersions(string &version) {
        vector<int> v;
        int n=0;
        for (int i=0; i<version.size(); ++i) {
            if (isdigit(version[i])) {
                n = n*10 + version[i] - '0';
            }
            else {
                v.push_back(n);
                n = 0;
            }
        }
        v.push_back(n);
        return v;
    }
    
    int compareVersion_verter(string &version1, string &version2) {
        if (version1 == version2) return 0;
        
        auto v1 = getVersions(version1);
        auto v2 = getVersions(version2);
        for (int i=0; i<max(v1.size(), v2.size()); ++i) {
            auto v1_num = (i < v1.size()) ? v1[i] : 0;
            auto v2_num = (i < v2.size()) ? v2[i] : 0;
            if (v1_num > v2_num) return 1;
            else if (v1_num < v2_num) return -1;
        }
        
        return 0;
    }
    
    int compareVersion_twopointers(string &version1, string &version2) {
        if (version1 == version2) return 0;
        
        int n1 = version1.size();
        int n2 = version2.size();
        int l=0, r=0;
        int v1=0, v2=0;
        while (l<n1 || r<n2) {
            while (l < n1 && isdigit(version1[l])) v1 = v1*10 + version1[l++] - '0';
            l++;
            while (r < n2 && isdigit(version2[r])) v2 = v2*10 + version2[r++] - '0';
            r++;
            
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            v1 = 0;
            v2 = 0;
        }
        
        return 0;
    }
    
    int compareVersion_stringstream(string &version1, string &version2) {
        istringstream iss1(version1), iss2(version2);
        while (iss1 || iss2) {
            char c;
            int n1 = 0, n2 = 0;
            if (iss1) iss1 >> n1 >> c;
            if (iss2) iss2 >> n2 >> c;
            
            if (n1 > n2) return 1;
            if (n1 < n2) return -1;
        }
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        //return compareVersion_verter(version1, version2);
        //return compareVersion_twopointers(version1, version2);
        return compareVersion_stringstream(version1, version2);
    }
};

int main()
{
    assert(Solution().compareVersion("0.1", "1.1") == (-1));
    assert(Solution().compareVersion("1.0.1", "1") == (1));
    assert(Solution().compareVersion("7.5.2.4", "7.5.3") == (-1));
    assert(Solution().compareVersion("1.01", "1.001") == (0));
    assert(Solution().compareVersion("1.0", "1.0.0") == (0));
    return 0;
}