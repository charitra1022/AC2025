// Task 1: 
// https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
// Date: 06-01-2023

// Time Complexity: O(N)
// Space complexity: O(1)


class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1])
                return 0;
        }
        return true;
    }
};
