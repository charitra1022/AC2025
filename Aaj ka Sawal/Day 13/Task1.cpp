// Day 13
// Task 1: Read about Binary Search and how it is implemented. You can use this blog to begin with:
// https://www.geeksforgeeks.org/binary-search/amp/
// Date: 13-01-2023

// Time Complexity:  O(logN)
// Space Complexity: O(1)
// Where N is size of the input array


#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int start=0, end=n-1, mid=0;
    
    while(start<=end) {
        mid = start+(end-start)/2;
        
        if(nums[mid]==target) 
            return mid;     // element found at mid position

        if(nums[mid]>target) 
            end=mid-1;      // mid element is greater tha target, so making it end

        else
            start=mid+1;    // mid element is smaller than target, so making it start
    }
    return -1;      // not found
}


int main(int argc, char const *argv[])
{
    vector<int> n1 = {1,5,6,9,10,23,65};
    int key1 = 23;
    cout << search(n1, key1) << endl;
    
    vector<int> n2 = {1,5,6,9,10,23,65};
    int key2 = 90;
    cout << search(n2, key2);

    return 0;
}
