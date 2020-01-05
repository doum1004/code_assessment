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

int minimumSwaps(vector<int> arr) {
    auto n = arr.size();
    pair<int, int> sorted[n];
    for (auto i = 0; i < n; i++)
    {
        sorted[i].first = arr[i];
        sorted[i].second = i;
    }
    sort(sorted, sorted + n);
    
    auto count = 0;
    vector<int> vis(n, false);
    for (auto i = 0; i < n; i++)
    {
        if (vis[i] || sorted[i].second == i)
            continue;

        auto cycle_count = 0;
        auto j = i;
        while (!vis[j])
        {
            vis[j] = true;
            j = sorted[j].second;
            cycle_count++;
        }

        if (cycle_count > 0)
            count += cycle_count - 1;
    }

    return count;
}

int main() {
    cout << "Input " << minimumSwaps(vector<int> {4, 3, 1, 2}) << endl;
    cout << "Input " << minimumSwaps(vector<int> {2, 3, 4, 1, 5}) << endl;
    cout << "Input " << minimumSwaps(vector<int> {1, 3, 5, 2, 4, 6, 7}) << endl;
    cout << "Input " << minimumSwaps(vector<int> {2, 3, 4, 1, 9}) << endl;
    return 0;
}