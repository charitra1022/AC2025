// Task 2: 
// https://leetcode.com/problems/rotate-image/
// Date: 04-01-2023

// Time: O(N^2)
// Space: O(1)


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // First transpose the matrix
        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        // Then swap column(i) from first with column(i) from end
        for(int j=0; j<n/2; j++)
            for(int i=0; i<n; i++)
                swap(matrix[i][j], matrix[i][n-1-j]);
    }
};
