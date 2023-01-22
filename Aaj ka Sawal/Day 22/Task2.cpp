// Day 22
// Task 2: https://leetcode.com/problems/contains-duplicate/description/
// Date: 22-01-2023


// APPROACH 1: Use set and compare set size with vector size
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// where N is the size of input vector
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // store only distinct elements
        set<int> distinctNum = set(nums.begin(), nums.end());

        if(nums.size()==distinctNum.size()) 
            return false;       // all elements are distinct
        return true;  
    }
};


// APPROACH 2: Sort vector and see if next element is equal to current element
// Time Complexity: O(NlogN)
// Space Complexity: O(1)
// where N is the size of input vector
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // sort elements in ascending order
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            // next element is same as current
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};


// APPROACH 3: Use hash map to store count of element
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// where N is the size of input vector
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // store count of distinct elements
        map<int, int> count;
        for(int i: nums) count[i]++;

        for(auto i: count) {
            // if element is present more than once
            if(i.second > 1)
                return true;
        }
                
        return false;
    }
};
