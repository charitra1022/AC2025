// Day 27
// Task 1: https://leetcode.com/problems/maximum-average-subarray-i/description/
// Date: 27-01-2023


// APPROACH: sliding window
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the size of the vector

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;   // store current sum

        for(int i=0; i<k; i++)
            sum += nums[i];   // sum of current window

        double maxSum = sum;  // store max sum
        for(int i=1; i<=nums.size()-k; i++) {
            sum -= nums[i-1];   // remove last element of previous window
            sum += nums[i+k-1]; // add last element of current window
            maxSum = max(maxSum, sum);  // get max of previous and current sum
        }

        return maxSum/k;    // return the average
    }
};
