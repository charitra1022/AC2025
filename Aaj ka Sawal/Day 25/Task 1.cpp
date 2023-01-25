// Day 25
// Task 1: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/
// Date: 25-01-2023


// APPROACH: sort both arrays and compare
// Time Complexity: O(NlogN)
// Space Complexity: O(1)
// where N is the size of the vector

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p = players.size(), t = trainers.size();

        int count = 0, i=0, j=0;
        // loop till at least one of the vectors end
        while(i<p && j<t) {
            if(players[i] <= trainers[j]){
                // required condition for matching
                count++;    // increment match count
                i++;        // move to next player
                j++;        // move to next trainer
            } 
            else j++;   // trainer incapable, so move to next trainer
        }
        return count;
    }
};
