// Day 25
// Task 2: https://leetcode.com/problems/merge-sorted-array/description/
// Date: 25-01-2023



// APPROACH 1: using new array and then copying that into given input array
// Time Complexity: O(M+N)
// Space Complexity: O(M+N)
// where N, M is the size of the vectors given

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        vector<int> newArr;     // new array for final sorted array
        // till one of them gets over
        while(i<m && j<n){
            // element in nums2 is greater
            if(nums1[i] < nums2[j])
                newArr.push_back(nums1[i++]);
            
            // element in nums1 is greater
            else if(nums1[i] > nums2[j])
                newArr.push_back(nums2[j++]);
            
            // element in both are same
            else if(nums1[i] == nums2[j]) {
                newArr.push_back(nums1[i++]);
                newArr.push_back(nums2[j++]);
            }

            // if element is 0, means empty space
            else if(nums1[i] == 0)
                newArr.push_back(nums2[j++]);
        }

        // add remaining elements of nums
        while(i<m) newArr.push_back(nums1[i++]);
        // add remaining elements of nums2
        while(j<n) newArr.push_back(nums2[j++]);

        // copy newArr into nums1
        nums1 = newArr;
    }
};



// APPROACH 2: using two pointers
// Time Complexity: O(M+N)
// Space Complexity: O(1)
// where N, M is the size of the vectors given

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // k is for pointing to the index where to insert
        // i is the end of nums1
        // j is the end of nums2
        int k=m+n-1, i=m-1, j=n-1;

        // loop till all places are filled
        while(k>=0) {
            // nums2 is fully traversed, so insert from nums1 only
            if(j<0){
                nums1[k--] = nums1[i--];
                continue;
            }
            // nums1 is fully traversed, so insert from nums2 only
            if(i < 0) {
                nums1[k--] = nums2[j--];
                continue;
            }

            // right element of nums2 is larger, so insert that
            if(nums1[i] < nums2[j])
                nums1[k--] = nums2[j--];
            // right element of nums1 is larger, so insert that
            else if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            // both elements are same, so insert both
            else {
                nums1[k--] = nums2[j--];
                nums1[k--] = nums1[i--];
            }
        }
    }
};

