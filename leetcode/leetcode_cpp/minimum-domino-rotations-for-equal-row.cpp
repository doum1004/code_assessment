#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

Solution1: find all possibil nums. and find min swap num
time: o(n^2)
space: o(1). space only takes 1~6

1. count nums in each row
2. find list of num which are sum of a,b rows equal or more than 6
3. check mergable. merge less count row to more count row. and check diff count. and find min diff count

Solution2. Greedy
//time: o(n)
//space: o(1)

1. Pick nums in first of each array
2. Give each nums in Iteration i(begin to end)
2.1 check num exist either or both of array
2.2 count rotation a, b and return min
3. return min result if they have result

*/

class Solution {
public:
    int minDominoRotations_count(vector<int>& A, vector<int>& B) {
        int n_a = A.size();
        int n_b = B.size();
        if (n_a < 1 || n_b < 1 || n_a != n_b) throw invalid_argument("");
        
        unordered_map<int,int> count_a, count_b;
        for (auto &n:A) count_a[n]++;
        for (auto &n:B) count_b[n]++;
        
        int minRotation = INT_MAX;
        for (auto &node:count_a) {
            auto n = node.first;
            auto a = node.second;
            auto b = count_b[n];
            if (a+b >= n_a) {
                auto succeeded = true;
                auto rotation_a = 0;
                auto rotation_b = 0;
                
                for (int i=0; i<n_b; ++i) {
                    if (A[i] != n && B[i] != n) {
                        succeeded = false;
                        break;
                    }

                    if (A[i] != n) {
                        rotation_b++;
                    }
                    if (B[i] != n) {
                        rotation_a++;
                    }
                }
                
                if (succeeded) {
                    minRotation = min(minRotation, min(rotation_a, rotation_b));
                } 
            }
        }
        
        return minRotation == INT_MAX ? -1 : minRotation;
    }
    
    int rotateResult(vector<int>& A, vector<int>& B, int num) {
        int rotate_a = 0;
        int rotate_b = 0;
        for (int i=0; i<A.size(); ++i) {
            if (num != A[i] && num != B[i]) return -1;
            if (A[i] == B[i]) continue;
            if (num == A[i]) rotate_a++;
            if (num == B[i]) rotate_b++;
        }
        return min(rotate_a, rotate_b);
    }
    
    int minDominoRotations_greedy(vector<int>& A, vector<int>& B) {
        auto result_1 = rotateResult(A, B, A[0]);
        auto result_2 = (A[0] != B[0]) ? rotateResult(A, B, B[0]) : result_1;
        
        if (result_1 == -1) return result_2;
        if (result_2 == -1) return result_1;
        return min(result_1, result_2);
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        //return minDominoRotations_count(A, B);
        return minDominoRotations_greedy(A, B);
    }
};

int main()
{
    auto input1_1 = vector<int> {2,1,2,4,2,2};
    auto input1_2 = vector<int> {5,2,6,2,3,2};
    assert(Solution().minDominoRotations(input1_1, input1_2)
        == 2);

    auto input2_1 = vector<int> {3,5,1,2,3};
    auto input2_2 = vector<int> {3,6,3,3,4};
    assert(Solution().minDominoRotations(input2_1, input2_2)
        == -1);

    return 0;
}