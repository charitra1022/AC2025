// Day 28
// Task 1: https://leetcode.com/problems/find-the-k-beauty-of-a-number/
// Date: 28-01-2023


// APPROACH: sliding window
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the number of digits of the input

class Solution {
public:
    int countDigits(int n) {
        // return the number of digits of the given number
        int count=0;
        while(n>0) {
            count++;
            n/=10;
        }
        return count;
    }

    int divisorSubstrings(int num, int k) {
        int digits = countDigits(num);  // digit count
        // r for trimming number from right
        // count to count number of substrings
        int r=digits-k, count=0;      

        // use sliding window concept
        for(int i=0; i<=digits-k; i++) {
            // trim number from right and left
            long n = (num/(long)pow(10, r-i))%(long)pow(10, k);

            // if the substring is beautiful, increment count
            if(n != 0 && num%n == 0) count++;
        }
        return count;
    }
};

