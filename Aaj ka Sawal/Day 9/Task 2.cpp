// Day 09
// Task 2: https://practice.geeksforgeeks.org/problems/sum-of-primes0042/1
// Date: 09-01-2023

// Time Complexity: O(logN)
// Space Complexity: O(1)

class Solution{
public:
    bool isDigitPrime(int digit) {
        // Checks if the digit is prime
        switch(digit) {
            case 2:
            case 3:
            case 5:
            case 7:
                return true;
                break;
            default:
                break;
        }
        return false;
    }

    int primeSum(int N){
        int sum = 0;    // store sum of the prime digits
        while(N > 0) {
            int d = N%10; // extract last digit
            if(isDigitPrime(d)) 
              sum += d;   // add to sum if it is prime

            N /= 10;      // remove last digit
        }
        return sum;
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
