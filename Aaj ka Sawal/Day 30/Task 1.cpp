// Day 30
// Task 1: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
// Date: 30-01-2023


// APPROACH: Sliding window
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the size of vector

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // sum to keep sum of window
        // threshold is average, so avg is total sum
        long long int sum = 0, avg = threshold*k;
        int count = 0, n = arr.size();
        
        // calculate first window
        for(int i=0; i<k; i++) 
            sum += arr[i];

        // increment if exceeds threshold
        if(sum >= avg) 
            count++;

        for(int i=1; i<=n-k; i++) {
            // remove last element from previous window
            sum -= arr[i-1];
            // last last element in current window
            sum += arr[i+k-1];
            
            // increment if exceeds threshold
            if(sum >= avg) count++;
        }

        return count;
    }
};
