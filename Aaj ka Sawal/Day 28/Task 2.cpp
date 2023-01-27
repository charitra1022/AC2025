// Day 28
// Task 2: https://leetcode.com/problems/sum-of-unique-elements/description/
// Date: 28-01-2023


// APPROACH: Store count of all elements and add only those that appear once
// Time Complexity: O(N)
// Space Complexity: O(1)  (used array of 101 size)
// where N is the size of the vectors given

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        // hash map to count element count
        int count[101] = {0};

        // store count of all numbers
        for(int i=0; i<nums.size(); i++)
            count[nums[i]]++;
        
        // sum only those elements that are present only once
        int sum = 0;
        for(int i=1; i<=100; i++)
            if(count[i] == 1) 
                sum += i;
        
        return sum;
    }
};

