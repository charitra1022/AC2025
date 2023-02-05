// Day 36
// Task 2: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// Date: 05-02-2023


// APPROACH: two pointer and linear search
// Time Complexity: O(N+M)
// Space Complexity: O(1)
// where N is the size of vector

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        // i for first array
        // j for second array
        // index for final array that would be formed by merging
        int i=0, j=0, index = 0;

        // iterate till any one array ends
        while(i<n && j<m) {
            // first element is smaller
            if(arr1[i] < arr2[j]) {
                index++;    // increment final array pointer
                // are we at required position
                if(k == index) 
                    return arr1[i];
                i++;    // move ahead in first array
            }

            // second element is smaller
            else if(arr1[i] > arr2[j]) {
                index++;    // increment final array pointer
                // are we at required position
                if(k == index) 
                    return arr2[j];
                j++;    // move ahead in second array
            }

            // both are same
            else {
                index++;    // increment final array pointer
                // are we at required position
                if(k == index) 
                    return arr1[i];
                i++;    // move ahead in first array
                
                index++;    // increment final array pointer
                // are we at required position
                if(k == index) 
                    return arr2[j];
                j++;    // move ahead in second array
            }
        }
        
        
        // if some elements in first array are left
        while(i<n) {
            index++;    // increment final array pointer
            // are we at required position
            if(k == index) return arr1[i];
            i++;    // move ahead in first array
        }
        
        
        // if some elements in second array are left
        int ans = -1;
        while(j<m) {
            index++;    // increment final array pointer
            // are we at required position
            if(k == index) {
                ans = arr2[j];
                break;
            }
            j++;    // move ahead in second array
        }
        return ans;
    }
};
