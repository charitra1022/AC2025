// Day 11
// Task 1: https://leetcode.com/problems/duplicate-zeros/description/
// Date: 11-01-2023

// Time Complexity: O(N)
// Space Complexity: O(N)
// where N is size of input array

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
      int n = arr.size();
      
      vector<int> newArr; // store new array
      int j=0;  // keep track of index of given array
      
      for(int i=0; i<n; i++, j++){
        // Push element if non-zero
        if(arr[j] != 0)
          newArr.push_back(arr[j]);
        
        // If found element is 0
        else {
          // Add two zeroes
          newArr.push_back(0);
          newArr.push_back(0);
          i++;  // increment counter variable
        }
      }
      
      for(int i=0; i<n; i++)
        // Copy elements to the input array
        arr[i] = newArr[i];
    }
};
