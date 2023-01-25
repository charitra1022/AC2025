// Day 24
// Task 1: https://leetcode.com/problems/two-sum/
// Date: 24-01-2023


// APPROACH 1: Brute: fix one element and run loop to find next
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// where N is the size of the vector

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // initial positions
        int pos1 = -1, pos2 = -1;

        // iterate over all numbers and fix them as one of the numbers of the pair
        for(int i=0; i<nums.size()-1; i++) {
            // iterate to find the next number
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j]==target-nums[i]) {
                    // if target found, store positions and break
                    pos1 = i;
                    pos2 = j;
                    break;
                }
            }
            // if the anyone of the positions are set, we got the answer
            if(pos2 != -1) break;
        }
        // return the positions
        return vector<int>{pos1, pos2};
    }
};



// APPROACH 2: Make a hash map to store elements in sorted order with their original position as their value, and make use of two pointers to get the sum.
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// where N is the size of the vector

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // store elements with their position in an ordered map
        multimap<int, int> hash;
        for(int i=0; i<nums.size(); i++)
            hash.insert(make_pair(nums[i], i));

        // store initial positions
        vector<int> pos{-1, -1};
        
        auto itL = hash.begin();    // starting iterator
        auto itR = hash.rbegin();   // starting from end iterator

        // iterate till both iterators don't reach the end
        while(itL!=hash.end() && itR!=hash.rend()) {
            int sum = itL->first + itR->first;  // store sum of the current elements

            // if the sum matches, store positions and break
            if(sum == target)  {
                pos[0] = itL->second;
                pos[1] = itR->second;
                break;
            }

            // if sum is smaller, move left iterator one step right
            else if(sum < target) itL++;
            
            // if sum is larger, move right iterator one step left
            else itR++;
        }
        return pos;
    }
};



// APPROACH 3: Iterate over all elements and if (target-element) is not present in the map, then insert the element with its position in the map.
// Time Complexity: O(N)
// Space Complexity: O(N)
// where N is the size of the vector

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using unordered as all operations have O(1) in best case
        unordered_map<int, int> hash;

        // store the required positions
        vector<int> pos{-1, -1};
        
        // iterate over the elements
        for(int i=0; i<nums.size(); i++) {
            int el = target-nums[i];    // other required number

            // if required number is present in the map already
            if(hash.find(el) != hash.end()) {
                pos[0] = i;
                pos[1] = hash[el];
                break;
            }
            // if not, insert the element with its position
            else
                hash.insert(make_pair(nums[i], i));
            
        }
        return pos;
    }
};