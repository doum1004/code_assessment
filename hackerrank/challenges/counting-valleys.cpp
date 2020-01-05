#include <iostream>

using namespace std;

int a(int n, string str) {
    int cur_level = 0;
    int count = 0;
    for (auto c : str) {
        if (c == 'D')
            cur_level--;
        else if (c == 'U')
        {
            cur_level++;
            if (cur_level == 0)
                count++;
        }
        else
            throw new exception();
    }

    return count;
}

int main() {
    cout << a(8, "UDDDUDUU") << endl;
    return 0;
}