// Day 23
// Task 1: https://leetcode.com/problems/spiral-matrix/description/
// Date: 23-01-2023


// APPROACH: Make a hash map, and mark the elements that have already been accessed
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)
// where N*M is the order of the matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // store row and column
        int n = matrix.size(), m = matrix[0].size();

        vector<int> spiral;     // store the elements
        vector<vector<bool>> traversed(n, vector<bool>(m, false));  // hash array

        // i for row, j for col, index for indexing of spiral
        int i=0, j=0, index=0;
        // direction to traversing
        bool right=true,left=false,up=false,down=false;

        // loop till all elements are accessed
        while(index < n*m) {
            // traverse in right direction 
            if(right && !traversed[i][j]) {
                spiral.push_back(matrix[i][j]);     // store the element in the vector
                traversed[i][j] = true;     // mark as done
                j++;        // move to right element
                index++;    // move to next element in indexing

                if(index >= n*m) 
                    break;  // break if all elements have been pushed
                if(j == m || traversed[i][j]){
                    // if the elements are traversed till the last limit, change direction
                    right = false;  // reset right direction
                    down = true;    // now traverse in down direction
                    i++;            // move down
                    j--;            // move horizontal pointer to left
                }
            }

            // traverse in down direction
            if(down && !traversed[i][j]) {
                spiral.push_back(matrix[i][j]);     // store the element in the vector
                traversed[i][j] = true;     // mark as done
                i++;        // move to down element
                index++;    // move to next element in indexing
                
                if(index >= n*m) 
                    break;  // break if all elements have been pushed
                if(i == n || traversed[i][j]){
                    // if the elements are traversed till the last limit, change direction
                    down = false;  // reset down direction
                    left = true;   // now traverse in left direction
                    i--;           // move up
                    j--;           // move horizontal pointer to left
                }
            }

            // traverse in left direction
            if(left && !traversed[i][j]) {
                spiral.push_back(matrix[i][j]);     // store the element in the vector
                traversed[i][j] = true;     // mark as done
                j--;        // move to left element
                index++;    // move to next element in indexing
                
                if(index >= n*m) 
                    break;  // break if all elements have been pushed
                if(j == -1 || traversed[i][j]){
                    // if the elements are traversed till the last limit, change direction
                    left = false;   // reset left direction
                    up = true;      // now traverse in up direction
                    i--;            // move up
                    j++;            // move horizontal pointer to right
                }
            }

            // traverse in up direction
            if(up && !traversed[i][j]) {
                spiral.push_back(matrix[i][j]);     // store the element in the vector
                traversed[i][j] = true;     // mark as done
                i--;        // move to up element
                index++;    // move to next element in indexing
                
                if(index >= n*m) 
                    break;  // break if all elements have been pushed
                if(i == -1 || traversed[i][j]){
                    // if the elements are traversed till the last limit, change direction
                    up = false;     // reset up direction
                    right = true;   // now traverse in right direction
                    i++;            // move down
                    j++;            // move horizontal pointer to right
                }
            }
        }
        return spiral;
    }
};
