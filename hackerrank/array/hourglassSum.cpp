#include <iostream>
#include <vector>

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    auto max_sum = -54;
    auto total_row = arr.size();
    auto total_col = arr[0].size();

    for (auto i = 1; i < total_row - 1; i++)
    {
        auto row = arr[i];
        for (auto j = 1; j < total_col - 1; j++)
        {
            max_sum = max(
                arr[i-1][j-1] +
                arr[i-1][j] +
                arr[i-1][j+1] +
                arr[i][j] +
                arr[i+1][j-1] +
                arr[i+1][j] +
                arr[i+1][j+1]
            , max_sum);
        }
    }

    return max_sum;
}

int main() {
    auto arr1 = vector<vector<int>> {
        {-9, -9, -9,  1, 1, 1},
        { 0, -9,  0,  4, 3, 2},
        {-9, -9, -9,  1, 2, 3},
        { 0,  0,  8,  6, 6, 0},
        { 0,  0,  0, -2, 0, 0},
        { 0,  0,  1,  2, 4, 0}
     };
    cout << "Input1 " << hourglassSum(arr1) << endl;
    return 0;
}