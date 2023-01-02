// Task 1: https://leetcode.com/problems/pascals-triangle/
// Date: 03-01-2023

// Time: O(N^2)
// Space: O(N^2)

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.emplace_back(vector<int> {1});

        for(int i=1; i<numRows; i++) {
            vector<int> row(i+1);
            row[0] = row[i] = 1;

            for(int j=1; j<i; j++){
                row[j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};
