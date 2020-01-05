#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c) {
    auto count = 0;
    auto index = 0;
    while (index < c.size() - 1)
    {
        if (c.size() > index + 1 && c[index + 2] == 0)
            index += 2;
        else
            index += 1;
        count++;
    }

    return count;
}

int main() {
    cout << jumpingOnClouds(vector<int> {0, 0, 1, 0, 0, 1, 0}) << endl;
    return 0;
}