#include <iostream>
#include <vector>

using namespace std;

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> result;
    for (auto i = 0; i < a.size(); i++) {
        auto index = (i + d) % a.size();
        result.push_back(a[index]);
    }
    return result;
}

string vectorToString(vector<int> a) {
    string str = "";
    for (auto v : a) {
        str += to_string(v);
    }
    return str;
}

int main() {
    cout << "Input1 " << vectorToString(rotLeft(vector<int> {1, 2, 3, 4, 5}, 54)) << endl;
    cout << "Input2 " << vectorToString(rotLeft(vector<int> {41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51}, 2010)) << endl;
    return 0;
}