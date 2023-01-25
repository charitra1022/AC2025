// Day 24
// Task 2: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Date: 24-01-2023


// APPROACH: fixed sliding window
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the size of the vector

class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        long sum = 0;   // store the sum of the window
        // store sum of the first window
        for(int i=0; i<k; i++) 
            sum += arr[i];
        
        // store max sum
        long maxSum = sum;
        
        // slide the window by one place in iteration
        for(int i=1; i<=n-k; i++){
            sum -= arr[i-1];        // remove left most element from the window sum
            sum += arr[i+k-1];      // add right most element in the new window sum
            maxSum = max(maxSum, sum);  // store max sum
        }
        return maxSum;
    }
};
