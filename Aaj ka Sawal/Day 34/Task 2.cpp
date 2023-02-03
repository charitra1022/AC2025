// Day 34
// Task 2: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Date: 03-02-2023


// APPROACH 1: sort and use two pointer
// Time Complexity: O(NlogN + MlogM)
// Space Complexity: O(1)
// where N,M are the sizes of input vectors

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // sort both vectors
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // two pointers for both vectors
        int i=0, j=0, n=nums1.size(), m=nums2.size();
        
        // to store intersection
        vector<int> inter;

        // loop till any one of them ends
        while(i<n && j<m) {
            // if same, add to vector
            if(nums1[i] == nums2[j]){
                inter.emplace_back(nums1[i]);
                i++;
                j++;
            } 
            
            // if first is greater, move second ahead
            else if(nums1[i] > nums2[j]) j++;

            // if second is greater, move first ahead
            else i++;
        }
        return inter;
    }
};


// APPROACH 2: store counts in map, and add common elements min count times
// Time Complexity: O(N+M)
// Space Complexity: O(N+M)
// where N,M are the sizes of input vectors

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // store counts of the elements in the maps
        // using unordered map as sorting is not required
        unordered_map<int, int> n1, n2;
        for(int i:nums1) n1[i]++;
        for(int i:nums2) n2[i]++;

        vector<int> inter;

        // if map1 is smaller, iterate map1
        if(n1.size() < n2.size()) {
            // traverse the pairs
            for(auto i: n1) {
                // get the minimum count of an element
                int count = min(i.second, n2[i.first]);
                // add this element the number of times it appears in both
                for(int j=0; j<count; j++)
                    inter.emplace_back(i.first);
            }
        }

        // otherwise iterate map2
        else {
            // traverse the pairs
            for(auto i: n2) {
                // get the minimum count of an element
                int count = min(i.second, n1[i.first]);
                // add this element the number of times it appears in both
                for(int j=0; j<count; j++)
                    inter.emplace_back(i.first);
            }
        }
        return inter;
    }
};
