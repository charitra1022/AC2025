// Day 22
// Task 1: https://leetcode.com/problems/isomorphic-strings/description/
// Date: 22-01-2023


// APPROACH 1: Using map
// Time Complexity: O(N)
// Space Complexity: O(M)
// where N is the length of the string
// where M is the number of distinct characters in string


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m1, m2;     // for storing both sided mappings
        int n = t.size();           // size of string

        for(int i=0; i<n; i++) {
            char c1 = s[i], c2 = t[i];  // get characters at i in both strings

            if(m1.find(c1) == m1.end() && m2.find(c2) == m2.end()){
                // if mapping for both doesnt exists
                m1.insert(make_pair(c1, c2));       // map c1 to c2
                m2.insert(make_pair(c2, c1));       // map c2 to c1
            } 
            else if (m1[c1] != c2 || m2[c2] != c1) {
                // if any one of the mappings dont match, return false
                return false;
            }
        }
        // all mappings matched, so return true
        return true;
    }
};


// APPROACH 2: Using hash array
// Time Complexity: O(N)
// Space Complexity: O(1)   // uses 256 sized hash array
// where N is the length of the string

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256, -1), m2(256, -1);   // for storing both sided mappings for all 256 ascii
        int n = t.size();           // size of string

        for(int i=0; i<n; i++) {
            char c1 = s[i], c2 = t[i];  // get characters at i in both strings

            if(m1[c1] == -1 && m2[c2] == -1) {
                // if mapping for both doesnt exists
                m1[c1] = c2;        // map c1 to c2
                m2[c2] = c1;        // map c2 to c1
            } else if (m1[c1] != c2 || m2[c2] != c1){
                // if any one of the mappings dont match, return false
                return false;
            }
        }
        // all mappings matched, so return true
        return true;
    }
};
