#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;
// test commit
void printVector(vector<bool> arr) {
    for (auto v : arr) {
        cout << v << ", ";
    }
    cout << endl;
}

void printVector(vector<int> arr) {
    cout << "size : " << arr.size() << endl;
    for (auto v : arr) {
        cout << v << ", ";
    }
    cout << endl;
}

void printVector(vector<char> arr) {
    cout << "size : " << arr.size() << endl;
    for (auto v : arr) {
        cout << v << ", ";
    }
    cout << endl;
}

void printVector(vector<string> arr) {
    cout << "size : " <<    arr.size() << endl;
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
