#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    auto a = unordered_set<int>();
    auto count = 0;
    for (auto v : ar) {
        auto it = a.find(v);
        if (it == a.end()) {
            a.insert(v);
        }
        else {
            a.erase(it);
            count++;
        }
    }
    return count;
}

int main()
{
    cout << sockMerchant(0, vector<int> {1, 1, 2, 2, 3}) << endl;
    return 0;
}