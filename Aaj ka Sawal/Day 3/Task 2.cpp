// Task 2: https://leetcode.com/problems/sort-colors/
// Date: 03-01-2023

// Time: 0(N)
// Space: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(int i: nums) {
            if(i == 0) red++;
            else if(i == 1) white++;
            else blue++;
        }
        int i = 0;
        while(i<red) nums[i++] = 0;
        while(i<red+white) nums[i++] = 1;
        while(i<red+white+blue)nums[i++] = 2;
    }
};
