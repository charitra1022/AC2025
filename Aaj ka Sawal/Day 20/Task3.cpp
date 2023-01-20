// Day 20
// Task 3: https://www.codechef.com/problems/GCDQ
// Date: 20-01-2023

// Time Complexity: O(NlogN) per test case
// Space Complexity: O(N)
// where N is the input number


/*
APPROACH: pre-computation
We will calculate running GCD of the array from left as well as from right
we will get the gcd before L and after R, and calculate their gcd
*/


#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    // calculate gcd of a and b
    if(b == 0) return a;
    return gcd(b, a%b);
}

// calculate cumulative gcd of array from left
vector<int> prefixGCD(vector<int> nums, int n) {
    vector<int> gcdArray(n+2, 0);   // take two extra space for element before 0 and after n-1
    gcdArray[1] = nums[0];          // first gcd will be same as element
    
    for(int i=1; i<n; i++)
        gcdArray[i+1] = gcd(nums[i], gcdArray[i]);  // calculate cumulative gcd
    return gcdArray;        // return gcd so calculated
}

// calculate cumulative gcd of array from right
vector<int> suffixGCD(vector<int> nums, int n) {
    vector<int> gcdArray(n+2, 0);   // take two extra space for element before 0 and after n-1
    gcdArray[n] = nums[n-1];        // first gcd will be same as element
    
    for(int i=n-2; i>=0; i--)
        gcdArray[i+1] = gcd(nums[i], gcdArray[i+2]);  // calculate cumulative gcd
    return gcdArray;        // return gcd so calculated
}

void driver() {
    // handle inputs
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    
    // precomputed gcd from left and right
    vector<int> preGCD = prefixGCD(nums, n);
    vector<int> sufGCD = suffixGCD(nums, n);
    
    for(int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        // gcd for requested range
        cout << gcd(preGCD[l-1], sufGCD[r+1]) << endl;
    }
    
}

// driver code for test cases
int main() {
	int t;
	cin >> t;
	while(t--) driver();
	return 0;
}
