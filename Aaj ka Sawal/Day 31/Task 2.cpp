// Day 31
// Task 2: https://leetcode.com/problems/range-sum-query-immutable/
// Date: 31-01-2023


// APPROACH: prefix sum
// Time Complexity: O(N)
// Space Complexity: O(1)  
// where N is the size of the vectors given

class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        // store prefix sum
        preSum.resize(n);
        
        // calculate prefix sum
        preSum[0] = nums[0];
        for(int i=1; i<n; i++)
            preSum[i] = preSum[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        // get sum till last range value
        int sum = preSum[right];

        // if left is 0, return total sum calculated
        if(left == 0) return sum;
        // otherwise subtract the sum in left part
        return sum-preSum[left-1];
    }
};
