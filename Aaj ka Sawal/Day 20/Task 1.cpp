// Day 20
// Task 1: https://leetcode.com/problems/count-primes/description/
// Date: 20-01-2023

// Time Complexity: O(Nloglog(N))
// Space Complexity: O(N)
// where N is the input number


// APPROACH: sieve of eratosthenes 

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n+2, true);  // store prime number states

        // Run loop until the numbers whose squares exist in range
        for(int i=2; i*i <= n; i++) {
            if(sieve[i]) {
                // if the current number is prime, remove all its multiples starting from its square
                for(int j=i*i; j<=n; j+=i){
                    // remove [i*i, i*i+i, i*i+2i, . . .]
                    sieve[j] = false;
                }
            }
        }
        
        int count = 0;      // get count of primes
        // start from 2 and count all primes
        for(int i=2; i<n; i++) 
            if(sieve[i])
                count++;
        return count;
    }
};
