// Day 09
// Task 1: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
// Date: 09-01-2023

// Approach 1 (By divisiion)
// Time Complexity: O(logN)
// Space Complexity: O(1)

class Solution{
    public:
    bool isPowerofTwo(long long n){
        if(n == 0) 
          return false;   // edge case
        
        while(n > 0) {
            if(n%2 == 1 && n > 1) 
              return false;   // number is odd and greater than 1
            n /= 2;   // divide number by 2
        }
        return true;
    }
};




// Approach 2 (Bit Manipulation)
// Time Complexity: O(logN)
// Space Complexity: O(1)

class Solution{
    public:
    bool isPowerofTwo(long long n){

        if(n == 0) 
          return false;   // edge case

        while(n > 0) {
            int bit = n&1;  // get last bit
            if(bit == 1 && n>1) 
              return false; // last bit is 1, and number is odd and greater than 1
            n >>= 1;        // right shift the number
        }
        return true;
    }
};
