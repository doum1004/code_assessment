#include <iostream>
#include <vector>

using namespace std;

long repeatedString(string s, long n) {
    auto mod = n % s.length();
    cout << mod << endl;
    long count = 0;

    auto countInS = 0;
    for (auto c : s) {
        if (c == 'a')
        {
            countInS++;
            if (mod > 0)
                count++;
        }

        if (mod > 0)
            mod -= 1;
    }

    cout << count << endl;
    cout << countInS << endl;
    cout << n / s.length() << endl;
    count += n / s.length() * countInS;
    return count;
}

int main() {
    cout << "Input1 " << repeatedString("aba", 10) << endl;
    cout << "Input2 " << repeatedString("a", 1000000000000) << endl;
    return 0;
}