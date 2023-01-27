// Day 26
// Task 1: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/
// Date: 26-01-2023


// APPROACH: sliding window
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the size of the vector

class Solution {
public:
    bool isDistinct(char a, char b, char c) {
        // if any of the characters are same
        if(a == b || b == c || a == c) return false;
        return true;
    }

    int countGoodSubstrings(string s) {
        // if the string is less than 3 characters
        if(s.size() < 3) return 0;
        
        // count the number of required substrings
        int count = 0;

        // loop till last substring
        for(int i=0; i<s.size()-2; i++)
            if(isDistinct(s[i], s[i+1], s[i+2]))
                count++;    // if substring is required
        
        return count;
    }
};
