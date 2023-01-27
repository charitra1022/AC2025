// Day 26
// Task 2: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
// Date: 26-01-2023



// APPROACH 1: sliding window
// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the size of the vectors given

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // keep current and minimum count of white ballsd
        int wCount = 0, wCountMin = 0;
        int n = blocks.size();

        // calculate count in first window
        for(int i=0; i<k; i++)
            if(blocks[i] == 'W') 
                wCount++;

        // keep current count as minimum
        wCountMin = wCount;

        // calculate white count in all windows
        for(int i=1; i<=n-k; i++) {
            // remove previous window's end white balls
            if(blocks[i-1]=='W') wCount--;

            // add current window's end white balls
            if(blocks[i+k-1]=='W') wCount++;

            // get minimum count of white balls
            if(min(wCount, wCountMin) == wCount)
                wCountMin = min(wCount, wCountMin);
        }
        return wCountMin;
    } 
};


