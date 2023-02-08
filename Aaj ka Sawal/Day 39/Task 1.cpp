// Day 39
// Task 1: https://leetcode.com/problems/factorial-trailing-zeroes/description/
// Date: 08-02-2023


// APPROACH: count number of 2s and 5s in the prime factorization of the number
// Time Complexity: O(NlogN)
// Space Complexity: O(1)
// where N is the input number

class Solution {
public:
    // count number of times a number appears in prime factorization of the dividend
    int countNum(int n, int div) {
        // store count
        int count = 0;
        // till n is positive
        while(n > 0) {
            // if present
            if(n%div==0) count++;

            // not divisible by div, so break, as no further it will be found
            else break;

            // remove one occurence as already counted
            n /= div;
        }
        return count;
    }


    int trailingZeroes(int n) {
        // to store number of twos and fives in the range
        int twos = 0, fives = 0;

        // loop till n from 2
        for(int i=2; i<=n; i++) {
            // count number of 2s and 5s in the number
            twos += countNum(i, 2);
            fives += countNum(i, 5);
        }
        // return min of 2s and 5s, as same number of 2s and 5s are present in 10s
        return min(twos, fives);
    }
};
