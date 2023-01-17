// Day 17
// Task 2: 
// Date: 17-01-2023

// Time Complexity: O(logN)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int s=0, e=a.size()-1, mid, n=a.size(), ans;
        
        while(s<=e) {
            mid = (e-s)/2 + s;

            if(mid == 0 && (a[0] > a[1])) 
              return a[0];  // left most element is required

            else if(mid == n-1 && (a[n-1] > a[n-2])) 
              return a[n-1];  // right most element is required

            else {
                if(a[mid]>a[mid+1] && a[mid]>a[mid-1]) {
                    ans = a[mid];   // this is required element
                    break;
                }
                else {
                    if(a[mid] < a[mid+1]) 
                      s = mid+1;    // this element is less than next element
                    else 
                      e = mid-1;    // this element is greater than next element
                }
            }
        }
        return ans;
    }
};
