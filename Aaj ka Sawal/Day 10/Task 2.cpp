// Day 10
// Task 2: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
// Date: 10-01-2023

// Time Complexity: O(|S|)
// Space Complexity: O(|S|)
// Where |S| is length of supplied string


class Solution
{
    public:
    vector<string> splitStr(string s, char delimiter) {
        // extract words and returns all words as a vector of strings
        vector<string> words;       // store words
        
        string word = "";           // keep track of current word
        for(int i=0; i<s.size(); i++) {
            if(s[i] == delimiter) {
                // if delimiter is found, push word to vector, and reset the word
                words.push_back(word);  
                word = "";
            } 
            else word += s[i];  // add the character to the word
        }
        words.push_back(word);  // push the last word into the vector
        return words;
    }
    

    string reverseWords(string S) 
    { 
        vector<string> words = splitStr(S, '.');    // get all words
        reverse(words.begin(), words.end());    // reverse the sequence of words
        
        string newS = "";       // store new string
        for(int i=0; i<words.size(); i++) {
            newS += words[i];   // add word to the new string

            if(i < words.size()-1) 
                newS += '.';    // dont add . in last word
        }
        
        return newS;
    } 
};