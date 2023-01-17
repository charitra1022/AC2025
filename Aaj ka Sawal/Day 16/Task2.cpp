// Day 16
// Task 2: https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
// Date: 16-01-2023

// Time Complexity: O(logN)
// Space Complexity: O(1)



class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      int s=0, e=letters.size()-1, mid, ans=-1;
      
      while(s<=e){
        mid = (e-s)/2 + s;
  
        if(letters[mid]>target){
          ans = mid; // might be possible answer
          e = mid-1;
        } 
        else
          s = mid+1; // element is equal or less than the target
      }
      
      if(ans >= letters.size() || ans == -1)
        return letters[0]; // is answer is not what we need
      
      else 
        return letters[ans]; // got required answer
    }
};
