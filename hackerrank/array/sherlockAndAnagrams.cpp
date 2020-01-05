#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "../../utils.h"

using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.size() != s2.size())
    {
        return false;
    }

    int count[26] = {};
    for (int n=0; n < s1.size(); n++)
    {
        count[s1.at(n) - 'a']++;
        count[s2.at(n) - 'a']--;
    }

    for (int i=0; i<26; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int sherlockAndAnagrams(string s) {
    int ans = 0;
    int diff = 1;
    for (int i=0; i<s.size(); i++)
    {
        vector<string> substrs(0);
        for (int j=0; j<s.size()-diff+1; j++) {
            substrs.push_back(s.substr(j, diff));
        }
        
        printVector(substrs);

        for (int x=0; x<substrs.size() - 1; x++)
        {
            for (int y=x+1; y<substrs.size(); y++)
            {
                if (isAnagram(substrs[x], substrs[y]))
                {
                    ans++;
                }
            }
        }
        diff++;
    }
    cout << ans << endl;
    return ans;
}

int sherlockAndAnagrams2(string s) {
    int ana = 0;
    int diff = 1;
    for(int i=0;i<s.size()-1;i++){
        vector<string> substrings(0);
        for(int j=0;j<s.size()-diff+1;j++){
            substrings.push_back(s.substr(j,diff));
        }
        //printVector(substrings);
        for(int j=0;j<substrings.size();j++){
            sort(substrings[j].begin(),substrings[j].end());
        }
        for(int x=0;x<substrings.size();x++){
            for(int y=x+1;y<substrings.size();y++){
            if(substrings[x]==substrings[y]){
                //cout << substrings[x] << "," << substrings[y] << endl;
                ana++;
            }
        }
        }
        diff++;
    }

    //cout << ana << endl;
    return ana;
}

int main() {
    assert(sherlockAndAnagrams("abba") == 4);
    assert(sherlockAndAnagrams("abcd") == 0);
    assert(sherlockAndAnagrams("ifailuhkqq") == 3);
    assert(sherlockAndAnagrams("kkkk") == 10);
    assert(sherlockAndAnagrams("cdcd") == 5);
    return 0;
}