// Day 19
// Task 2: https://leetcode.com/problems/increasing-decreasing-string/description/
// Date: 19-01-2023

// Time Complexity: O(N)
// Space Complexity: O(N)
// where N is number of characters


class Solution {
public:
    string sortString(string s) {

        // get count of all distinct characters in the string
        int count[26] = {0};
        for(char i: s)
            count[i-'a']++;
        
        string str = "";    // store new string
        int n = s.size();   // number of characters

        bool isRev = false; // do we need to run loop in reverse direction (for largest char)
        int i = 0;          // keep track of the index

        // run loop till all characters are placed
        while(n > 0) {
            if(i == 26) {
                // if we reach end of the char count array
                i--;    // start from 25
                isRev = true;   // run loop in reverse
            } 
            else if(i == -1){
                // if we reach before the start of the char count array
                i++;    // start from 0
                isRev = false;  // run loop in normal direction
            }


            if(count[i] == 0)  {
                // if the count of the char is 0, skip to next char
                
                if(isRev) i--;  // incase of reverse, next is i-1
                else i++;       // incase of normal, next is i+1
                continue;
            }

            str += (i + 'a');   // append the character to the string
            count[i]--;         // decrease count after appending
            n--;                // 1 character placed, so decrease number of iterations

            if(isRev) i--;      // incase of reverse, next is i-1
            else i++;           // incase of normal, next is i+1

        }
        return str;
    }
};
