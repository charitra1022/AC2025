// Day 38
// Task 1: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/
// Date: 07-02-2023


// APPROACH: Straight Forward
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the max of number of total digits and total numbers


class Solution {
public:
    int digitsSum (int n) {
        // returns the sum of digits of a number
        int sum = 0;
        while(n > 0) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }


    int differenceOfSum(vector<int>& nums) {
        // get sum of all numbers
        int sum = 0;
        for(int i: nums) sum += i;

        // get sum of all digits in total
        int digitSum = 0;
        for(int i: nums) digitSum += digitsSum(i);

        // return absolute difference
        return abs(sum - digitSum);
    }
};
