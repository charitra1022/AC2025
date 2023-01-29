// Day 29
// Task 1: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
// Date: 29-01-2023


// APPROACH: keep track of the start and end of the word using two pointers
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// where N is the size of string


// 1. Using reverse in STL
class Solution {
public:
    string reverseWords(string s) {
        // l denotes start of a word
        int n = s.size(), l=0;

        // traverse whole string
        for(int i=0; i<n; i++) {
            // if character is a space, denotes end of word
            if(s[i] == ' ') {
                // reverse from l to i
                reverse(s.begin()+l, s.begin()+i);
                l = i+1;    // change start of next word
            }
        }
        // reverse last word
        reverse(s.begin()+l, s.end());
        return s;
    }
};

// 2. Using custom reverse
class Solution {
public:
    string reverseWords(string s) {
        // l denotes start of a word
        int n = s.size(), l=0;

        // traverse whole string
        for(int i=0; i<n; i++) {
            // if character is a space, denotes end of word
            if(s[i] == ' ') {
                // reverse from l to i
                for(int j=l, k=i-1; j<=(i+l-1)/2; j++, k--) 
                    swap(s[j], s[k]);
                l = i+1;        // change start of next word
            }
        }

        // reverse last word
        for(int j=l, k=n-1; j<=(l+n-1)/2; j++, k--) 
            swap(s[j], s[k]);
        return s;
    }
};
