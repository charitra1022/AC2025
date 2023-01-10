// Day 10
// Task 1: https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1
// Date: 10-01-2023

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution{
    public:
    void convertToWave(int n, vector<int>& arr){
        for(int i=0; i<arr.size(); i+=2) {
            if(i+1 > n-1) 
              break;  // skip if its the last element
            
            swap(arr[i], arr[i+1]); // swap the consecutive elements, and move ahead by 2 steps
        }
    }
};
