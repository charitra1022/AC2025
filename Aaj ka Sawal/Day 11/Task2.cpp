// Day 11
// Task 2: https://leetcode.com/problems/intersection-of-two-arrays
// Date: 11-01-2023

// Time Complexity: O(min(|A|, |B|))
// Space Complexity: O(|C|)
// where |A| is size of input array 1
// where |B| is size of input array 2
// where |C| is size of intersection(A, B)


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());   // sort first vector
        sort(nums2.begin(), nums2.end());   // sort second vector

        vector<int> inter;      // store intersection

        // i is first vector pointer
        // j is second vector pointer
        // prev is to keep track of last element pushed into the intersection vector
        int i=0, j=0, prev = -1;

        while(i<nums1.size() && j<nums2.size()) {
            // loop runs till the vector that gets over soon

            int n1 = nums1[i], n2 = nums2[j];   // elements at the current indices

            // elements are same
            if(n1 == n2) {
                // current element is different from last element pushed
                if(n2 != prev) {
                    inter.emplace_back(n2); // add element to the vector
                    prev = n2;              // save this as prev element
                }
                i++;    // increment first vector pointer
                j++;    // increment second vector pointer 
            } 
            
            // elements were different
            else {
                if(n1 < n2) i++;    // element at first vector was smaller, so move pointer ahead
                else j++;           // element at second vector was smaller, so move pointer ahead
            }
        }

        return inter;
    }
};
