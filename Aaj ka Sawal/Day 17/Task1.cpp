// Day 17
// Task 1: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/
// Date: 17-01-2023

// Time Complexity: O(N*M)
// Space Complexity: O(N)
// where N is the number of sentences
//       M is the number of characters in the longest sentence

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        vector<int> wordCount(sentences.size());
        
        for(int i=0; i<sentences.size(); i++){
            // Traverse each sentence
            
            for(int j = 1; j < sentences[i].size(); j++) {
                // Traverse each character of the sentence

                // Count++ if the current char is space and previous was not a space
                if(sentences[i][j] == ' ' && sentences[i][j-1] != ' ') 
                    wordCount[i]++;
            }
            // increment for the last word that remained uncounted
            wordCount[i]++;
        }
        
        // Return the max of all counts
        return *max_element(wordCount.begin(), wordCount.end());
    }
};
