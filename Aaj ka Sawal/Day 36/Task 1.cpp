// Day 36
// Task 1: https://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1
// Date: 05-02-2023


// APPROACH: Binary Search
// Time Complexity: O(logN)
// Space Complexity: O(1)
// where N is the size of vector

class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int k) {
        int s = 0, e = n-1, mid, ans=-1;

        while(s <= e) {
            mid = (e-s)/2+s;

            // element found
            if(arr[mid] == k) return mid;

            // element is greater than required
            // this position might be answer, so store
            if(arr[mid] > k) {
                ans = mid;
                e = mid-1;
            } 
            // element is smaller than required, so move right in search space
            else s = mid+1;
        }

        // if we couldnt get required position, then it might be extreme ends
        if(ans == -1) {
            // is last position needed
            if(k > arr[n-1])
                ans = n;
            // is first position needed
            else if(k < arr[0])
                ans = 0;
        }
        return ans;
    }
};
