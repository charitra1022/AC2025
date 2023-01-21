// Day 21
// Task 1: https://leetcode.com/problems/valid-palindrome/description/
// Date: 21-01-2023



// APPROACH 1: Creating new string with only valid characters.
// Time Complexity: O(N)
// Space Complexity: O(N)
// where N is the length of the string


class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";   // store new string

        for(char i: s) {
            // Add character to string only if it is alpha-numeric
            if(isalnum(i))
                newS += tolower(i);     // convert to lowercase before appending
        }

        // Traverse only half the new string, and compare chars from both ends with two pointers
        for(int i=0, j=newS.size()-1; i<newS.size()/2; i++, j--)
            if(newS[i] != newS[j])
                return false;
        return true;
    }
};



// APPROACH 2: Traversing the original string and comparing only the valid characters
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the length of the string

// This approach compares whole string, so characters already compared before, gets compared again.
// As the loop iterates for N,and not half way like previous approach

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;      // start an end pointers

        // Traverse whole string
        while(i < s.size() && j>=0) {
            if(!isalnum(s[i])){
                // found char from left side is non-alpha-numeric, so skip
                i++; 
                continue;
            }
            if(!isalnum(s[j])){
                // found char from right side is non-alpha-numeric, so skip
                j--;
                continue;
            }

            // compare the chars at left and right pointers.
            if(tolower(s[i]) != tolower(s[j])) 
                return false;
            i++;    // next char from left
            j--;    // next char from right
        }
        return true;
    }
};
