// Day 39
// Task 2: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// Date: 08-02-2023


// APPROACH: binary search
// Time Complexity: O(logN)
// Space Complexity: O(1)
// where N is the size of vector

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // if already sorted or only single element present
        if(nums[0] < nums[n-1] || n == 1) return nums[0];

        int s = 0, e = n-1, mid, ans = -1;
        // binary search
        while(s <= e) {
            mid = (e-s)/2+s;

            // element present on right side of graph
            if(nums[mid] < nums[0]) {
                if(nums[mid-1] > nums[mid]) {
                    // if mid is on the break point
                    ans = nums[mid];
                    break;
                } 
                e = mid-1;
            }
            // element present on left side of graph
            if(nums[mid] > nums[n-1])
                s = mid+1;
        }
        return ans;
    }
};
