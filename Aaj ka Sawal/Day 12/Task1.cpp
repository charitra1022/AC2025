// Day 12
// Task 1: https://leetcode.com/problems/count-prefixes-of-a-given-string/description/
// Date: 12-01-2023

// Time Complexity: O(N*M)
// Space Complexity: O(1)
// where N is size of string s
//       M is size of longest string in vector of words

class Solution {
public:
    bool isPrefix(string s, string word) {
        // Returns true if word is prefix of te string s
        if(s.size() < word.size()) 
            return false;  // size of string word is more than s, so can't be prefix

        int i=0, j=0;     // i for s, j for word
        
        while(j < word.size()) {
            // Loop all letters in word and compare with s
            
            if(s[i] != word[j]) 
                return false;   // at any point if characters dont match
            
            i++;
            j++;
        }
        return true;    // loop ran successfully
    }

    int countPrefixes(vector<string>& words, string s) {
        int count = 0;

        for(string word: words)
            if(isPrefix(s, word)) 
                count++;

        return count;
    }
};
