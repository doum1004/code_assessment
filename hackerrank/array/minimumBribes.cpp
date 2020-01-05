#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void printVector(vector<bool> arr) {
    for (auto v : arr) {
        cout << v << ", ";
    }
    cout << endl;
}

void printVector(vector<int> arr) {
    for (auto v : arr) {
        cout << v << ", ";
    }
    cout << endl;
}

void printPair(pair<int, int> arr[], int n) {
    for (auto i = 0; i < n; i++) {
        cout << arr[i].first << "(" << arr[i].second << ") ";
    }
    cout << endl;
}

void minimumBribes(vector<int> q) {
    int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--)
    {
        if (q[i] - (i + 1) > 2)
        {
            cout << "Too chaotic" << endl;
            return;
        }

        for (int j = max(0, q[i] - 2); j < i; j++)
        {   
            if (q[j] > q[i]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    minimumBribes(vector<int> {2, 1, 5, 3, 4}); // 3
    minimumBribes(vector<int> {2, 5, 1, 3, 4});
    minimumBribes(vector<int> {5, 1, 2, 3, 7, 8, 6, 4});
    minimumBribes(vector<int> {1, 2, 5, 3, 7, 8, 6, 4}); // 7
    minimumBribes(vector<int> {1, 2, 5, 3, 4, 7, 8, 6}); // 4
    //cout << "Input " << minimumBribes(vector<int> {2, 1, 5, 3, 4}) << endl;
    //cout << "Input " << minimumBribes(vector<int> {2, 5, 1, 3, 4}) << endl;
    return 0;
}