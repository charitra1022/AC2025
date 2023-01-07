// Day 08 
// Task 1: https://bit.ly/3PrGIjT
// Date: 08-01-2023

// Time Complexity: O(N)
// Space Complexity: O(1)


class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {

	    int index = 0;  // points to the index of non-zero element in new array alignment
	    
      for(int i=0; i<n; i++) {
	        if(arr[i] == 0) 
            continue;   // if 0 is found skip to next element
	        else {
	            arr[index] = arr[i];  // if non-zero found, move it to "index" position
	            index++;              // point to next position
	        }
	    }

	    for(int i=index; i<n; i++) 
        arr[i] = 0;   // after positioning all non-zero elements, fill zero
	}
};