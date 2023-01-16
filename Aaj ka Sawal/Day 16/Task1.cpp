// Day 16
// Task 1: https://leetcode.com/problems/first-bad-version/
// Date: 16-01-2023

// Time Complexity: O(logN)
// Space Complexity: O(1)


class Solution {
public:
    int guessNumber(int n) {
        int s=0, e=n, mid, ans;
        while(s <= e) {
            mid = (e-s)/2 + s;
            int state = guess(mid);
            
            // If number is found, store and break out of loop
            if(state == 0) {
                ans = mid;
                break;
            }

            // Number is greater than required number
            else if(state == -1) 
                e = mid-1;

            // Number is smaller than required number
            else 
                s = mid+1;
        }
        return ans;
    }
};
