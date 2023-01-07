// Day 08 
// Task 2: https://bit.ly/3dudCD8
// Date: 08-01-2023

// Time Complexity: O(N)
// Space Complexity: O(1)


class Solution{
public:	
	int search(int arr[], int N){

	    int num = -1;		// number that appears once

	    for(int i=0; i<N-1; i++) {
	        if(arr[i] == arr[i+1]) 
						i++;		// next element is same as current, move to next than next element
	        else {
	            num = arr[i];	// number is found once
	            break;
	        }
	    }
	    if(num == -1) 
				return arr[N-1]; // in case the last element is found once
	    
			return num;
	}
};
