// Day 21
// Task 2: https://leetcode.com/problems/counting-bits/description/
// Date: 21-01-2023

// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// where N is the input number


// APPROACH: count number of 1's in the binary repr of all numbers from 0 to n

class Solution {
public:
    int countBit(int n) {
        int count = 0;          // store 1 count
        while(n > 0){
            // loop until number gets to 0
            
            if(n&1) 
                count++;        // last bit is found to be 1
            n >>= 1;            // right shift by 1
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> bits(n+1);      // store counts of all numbers
         
        for(int i=0; i<=n; i++)
            bits[i] = countBit(i);
        
        return bits;
    }
};
