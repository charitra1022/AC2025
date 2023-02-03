// Day 30
// Task 2: https://leetcode.com/problems/prime-arrangements/description/
// Date: 30-01-2023


// APPROACH: Sieve of Eratosthenes
// Time Complexity: O(NloglogN)
// Space Complexity: O(1)  
// where N is the size of the vectors given

class Solution {
public:
    int numberOfPrimes(int n) {
        // calculates number of primes in [1-n]
        if(n == 1) return 0;

        vector<bool> sieve(n+1, true);
        sieve[0] = sieve[1] = false;

        // sieve of eratosthenes
        for(int i=2; i*i<=n; i++) {
            if(sieve[i]){
                for(int j=i*i; j<=n; j+=i) 
                    sieve[j]=false;
            }
        }
        
        // count number of primes
        int count = 0;
        for(bool i: sieve) if(i) count++;
        return count;
    }

    long long int factorial(int n) {
        // calculate factorial
        if(n == 1 || n == 0) return 1;
        long long int fact = 1;
        for(int i=1; i<=n; i++) {
            fact = (fact*i)%1000000007;
        }
        return fact;
    }


    int numPrimeArrangements(int n) {
        // if 1, only 1 permutation is possible
        if(n == 1) return 1;
        
        // number of prime number and non-primes
        int primes = numberOfPrimes(n);
        int nonPrimes = n-primes;

        // total number of permutations is n!*r!
        return (int)((factorial(primes) * factorial(nonPrimes)) % 1000000007);
    }
};
