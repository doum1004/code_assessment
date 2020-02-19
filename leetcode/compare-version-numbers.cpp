#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>

using namespace std;

/**
https://leetcode.com/problems/compare-version-numbers/

// solution1. String to vector. and vector comparison
// time: o(n+m)
// space: o(n+m)

1. get vector from string. iterate string accumulate int and add in vector if it faces '.'
2. compare vectors

// solution2. Find version before and compare till end
// time: o(n+m)
// space: o(1)

// solution3. Istringstream. iss >> long >> char
// time: o(n+m)
// space: o(1)

*/

class Solution {
public:
    vector<int> versionVector(string &s) {
        vector<int> versions;
        
        int v = 0;
        for (auto &c:s) {
            if (isdigit(c)) {
                v = v * 10 + (c - '0');
            }
            else {
                versions.push_back(v);
                v = 0;
            }
        }
        versions.push_back(v);
        
        return versions;
    }
    
    int compareVersion_solution1(string &version1, string &version2) {
        auto v1 = versionVector(version1);
        auto v2 = versionVector(version2);
        
        int n = max(v1.size(), v2.size());
        for (int i=0; i<n; ++i) {
            auto v1_val = (v1.size() <= i) ? 0 : v1[i];
            auto v2_val = (v2.size() <= i) ? 0 : v2[i];
            if (v1_val > v2_val) return 1;
            else if (v1_val < v2_val) return -1;
        }
        
        return 0;
    }
    
    int compareVersion_solution2(string &version1, string &version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        
        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            int v1 = 0;
            while (i < n1 && isdigit(version1[i])) {
                v1 = v1 * 10 + (version1[i++] - '0');
            }
            i++;
            
            int v2 = 0;
            while (j < n2 && isdigit(version2[j])) {
                v2 = v2 * 10 + (version2[j++] - '0');
            }
            j++;
            
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
        }
        
        return 0;
    }
    
    int compareVersion_solution3(string &version1, string &version2) {
        istringstream iss1(version1), iss2(version2);
        while (iss1 || iss2) {
            char dot;
            long v1 = 0, v2 = 0;
            if (iss1) iss1 >> v1 >> dot;
            if (iss2) iss2 >> v2 >> dot;
            
            if (v1 != v2) return (v1 > v2) ? 1 : -1;
        }
        
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        //return compareVersion_solution1(version1, version2);
        //return compareVersion_solution2(version1, version2);
        return compareVersion_solution3(version1, version2);
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