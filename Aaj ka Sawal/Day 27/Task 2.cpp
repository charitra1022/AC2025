// Day 27
// Task 2: 
// Date: 27-01-2023


// APPROACH: Count total vowels, use two pointers to exchange the vowels
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N, M is the size of the vectors given

class Solution {
public:
    bool isVowel(char c) {
        // count number of vowels
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }

    string reverseVowels(string s) {
        // get count of all vowels
        int count = 0;
        for(char c: s)
            count += isVowel(c);

        // two pointer, one from start and one from end
        // keep count of all swaps
        int i = 0, j = s.size()-1, swapped = 0;

        // loop till we swapped half of the total vowels
        while(swapped < count/2) {
            // char from start is not a vowel
            if(!isVowel(s[i])) {
                i++;
                continue;
            }
            // char from end is not a vowel
            if(!isVowel(s[j])) {
                j--;
                continue;
            }

            // swap the vowels
            swap(s[i], s[j]);
            i++;
            j--;
            swapped++;
        }

        return s;
    }
};

