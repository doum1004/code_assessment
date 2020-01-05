#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "../../utils.h"

using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {
    auto result = false;
    if (magazine.size() >= note.size())
    {
        auto mapper = unordered_map<string, int>(magazine.size());
        for (auto w : magazine)
        {
            mapper[w]++;
        }

        try
        {
            result = true;
            for (auto w : note)
            {
                if (mapper[w] > 0)
                    mapper[w]--;
                else
                {
                    result = false;
                    break;
                }
            }    
        }
        catch (...)
        {
            result = false;
        }
    }

    if (result)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    checkMagazine(
        vector<string> {"two", "times", "three", "is", "not", "four"},
        vector<string> {"two", "times", "two", "is", "four"}); // No
    checkMagazine(
        vector<string> {"ive", "got", "a", "lovely", "bunch", "of", "coconuts"},
        vector<string> {"ive", "got", "some", "coconuts"}); // No
    return 0;
}