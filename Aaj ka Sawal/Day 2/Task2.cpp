// Given a string, remove the vowels from the string
// Link: https://practice.geeksforgeeks.org/problems/remove-vowels-from-string1446/1

// Time Complexity: O(N)
// Space Complexity: O(N)


class Solution{
public:	
    bool isVowel(char c){
        // Function to check if character is vowel
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            return true;
        return false;
    }
    
    string removeVowels(string S) {
        string newS = "";
        for(char i: S){
            if(isVowel(i))
                continue; // skip if vowel
            else
                newS+=i; // append otherwise
        }
        return newS;
    }
};
