// Day 18
// Task 1: https://leetcode.com/problems/create-target-array-in-the-given-order/
// Date: 18-01-2023

// Time Complexity: O(N^2)
// Space Complexity: O(N)
// where N is the number of elements

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();    // size of given arrays
        vector<int> target;     // store new array


        // Approach 1 (by using STL)
        // vector.insert(iterator_to_insertion_position, value)
        for(int i=0; i<n; i++)
            target.insert(target.begin()+index[i], nums[i]);
        

        // Approach 2 (implementing insertion logic)
        for(int i=0; i<n; i++) {
            target.emplace_back(-1);    // just to create extra space in vector

            for(int j=target.size()-1; j>index[i]; j--)
                target[j] = target[j-1];    // right shift elements until position is reached
            target[index[i]] = nums[i];     // insert at the position
        }
        return target;
    }
};
