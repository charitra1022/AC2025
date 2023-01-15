// Day 15
// Task 1: https://leetcode.com/problems/first-bad-version/
// Date: 15-01-2023

// Time Complexity: O(logN)
// Space Complexity: O(1)


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      int s=1, e=n, mid, ans;

      while(s<=e){
        mid=(e-s)/2+s;

        if(isBadVersion(mid)){
          // If selected number is bad
          e = mid-1;  // check in left side for starting point of bad number
          ans = mid;  // store the current number as starting point
        }

        else 
          s=mid+1;  // if not bad, check in right side
      }
      return ans;
    }
};
