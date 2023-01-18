// Day 18
// Task 2: https://leetcode.com/problems/lemonade-change/description/
// Date: 18-01-2023

// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is number of bills


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0, c20 = 0; // store count of the coins

        for(int i: bills) {
            if(i == 5) c5++;  // if 5 is received, simply store

            else if(i == 10) {
                // if 10 is received, decrement 5 count, increment 10 count
                if(c5 == 0) return false; // no 5 is remaining, so return false
                c5--;   // decrement 5
                c10++;  // increment 10
            } 
            
            else {
                // if 20 is received, give ($5,$5,$5) or ($5,$10)

                if(c5 == 0) return false;   // no $5, so return false
                if(c10 == 0) {
                    // no $10, so, check if we have ($5,$5,$5)
                    if(c5 < 3) return false;  // not enough $5, so return false
                    c5 -= 3;  // enough $5 left, so decrement 3 $5
                } else {
                    // $10 is present, so give ($5, $10)
                    c10--;
                    c5--;
                }
                c20++;  // increment $20
            }
        }
        return true;
    }
};