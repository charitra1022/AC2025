// Day 12
// Task 2: https://practice.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1
// Date: 12-01-2023

// Time Complexity: O(N)
// Space Complexity: O(M)
// where N is size of input array
// where M is number of distinct elements in the array


class Solution{
    public:
    int firstElementKTime(int arr[], int n, int k) {
        int ans = -1;       // initially ans is -1

        map<int, int> counter;  // store count of all numbers
        
        for(int i=0; i<n; i++) {
            counter[arr[i]]++;  // increment count of the element

            if(counter[arr[i]] >= k) {
                // If the element occured k times
                ans = arr[i];   // store element in the ans
                break;
            }
        }
        return ans;             // return required ans
    }
};

