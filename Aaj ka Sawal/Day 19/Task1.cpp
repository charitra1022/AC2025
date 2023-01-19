// Day 19
// Task 1: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/
// Date: 19-01-2023

// Time Complexity: O(N)
// Space Complexity: O(M)
// where N is the total number of characters
//       M is number of distinct characters


class Solution {
public:
    bool areOccurrencesEqual(string s) {

        // keep count of all distinct characters
        map<char, int> count;   
        for(char i: s) 
            count[i]++;
        
        // get count of first character
        int prev = count.begin()->second;

        // if count of the any character is not equal to count of first character, return false
        for(auto i: count) 
            if(i.second != prev)
                return false;   
        
        // loop executed successfully
        return true;
    }
};
