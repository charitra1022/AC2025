// Day 20
// Task 2: https://codeforces.com/problemset/problem/17/A
// Date: 20-01-2023

// Time Complexity: O(N^2)
// Space Complexity: O(N)
// where N is the input number


// APPROACH: sieve of eratosthenes

#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrimes(int n) {
  // Get vector of all prime numbers between 2 to n
  vector<bool> sieve(n+1, true);  // prime number sieve
  vector<int> primes;             // store prime numbers

  // calculate sieve of eratosthenes
  for(int i=2; i*i <= n; i++) {
    if(sieve[i]) {
      for(int j=i*i; j<=n; j+=i) {
        sieve[j] = false;
      }
    }
  }

  // get all prime numbers
  for(int i=2; i<=n; i++) {
    if(sieve[i]){
      primes.emplace_back(i);
    }
  }
  return primes;
}

bool isPossible(int n, int k, vector<int> primes) {
  // returns true if it is possible to get at least k prime numbers
  
  if(k == 0) 
    return true;    // if k==0, always true
  
  if(primes.size() < k+2)
    return false;   // not enough primes numbers to get at least k

  int count = 0;    // get count of such pairs
  
  // start from last prime number and check if can be expressed as required sum
  for(int i=primes.size()-1; i>=0; i--) {
    int num = primes[i];    // number to be broken

    // start search from i-1 prime numbers
    for(int j = i-1; j>0; j--) {
      if(primes[j]+primes[j-1]+1 == num) {
        count++;    // we get the required pair of primes
        break;      // now move to find next prime number that can be broken
      }
    }
    if(count >= k) 
      return true;  // got enough number of primes that can be expressed in the required form
  }
  return false;     // could not get enough primes
}

int main() {
  int n, k;
  cin >> n >> k;    // inouts

  vector<int> primes = getPrimes(n);    // get all primes less than or equal to n
  
  // Print YES if got solved, else NO
  if(isPossible(n, k, primes))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}