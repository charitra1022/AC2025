// Day 14
// Task 2: https://leetcode.com/problems/search-insert-position/description/
// Date: 14-01-2023

// Time Complexity: O(logN)
// Space Complexity: O(1)
// where N is size of input array



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int s=0, e=nums.size(), mid, ans = -1;

        while(s < e) {
            mid = (e-s)/2 + s;

            if(nums[mid] == target) 
                return mid;   // element found

            if(nums[mid] > target) {
                // current element is greater than target, so element could be placed here
                ans = mid;    
                e = mid;
            } else {
                // current element is smaller than target, so element could be placed at next location
                ans = mid+1;
                s = mid+1;
            }
        }
        return ans;
    }
};
