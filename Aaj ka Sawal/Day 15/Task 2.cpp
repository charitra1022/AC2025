// Day 15
// Task 2: https://leetcode.com/problems/sqrtx/
// Date: 15-01-2023

// Time Complexity: O(logN)
// Space Complexity: O(1)


class Solution {
public:
    int mySqrt(int x) {
        int start=0, end = x, mid=0, ans=0;
        
        while(start<=end){
            mid = start+(end-start)/2;
            
            long long int n = (long long int)mid*mid;

            if(n==x) 
                return mid;     // if the number is required sqrt

            else if(n > x) 
                end = mid-1;    // if number is greater than square root
            else{
                start = mid+1;  // if number is smaller than square root
                ans = mid;      // store as answer
            }
        }
        return ans;
    }
};
