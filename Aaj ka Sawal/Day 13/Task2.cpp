// Day 13
// Task 2: https://leetcode.com/problems/maximum-ice-cream-bars/description/
// Date: 13-01-2023

// Time Complexity: O(NlogN)
// Space Complexity: O(1)
// where N is size of input array


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());   // sort by cost of ice-cream
        int count = 0;                      // number of ice-creams bought

        for(int i: costs) {
            if(i <= coins) {
                // if we have ample of coins left for this cost
                coins -= i;     // decrease coins by cost
                count++;        // increment the ice-cream count
            }
            if(coins == 0) 
                break;          // if coins become 0, exit
        }
        return count;
    }
};
