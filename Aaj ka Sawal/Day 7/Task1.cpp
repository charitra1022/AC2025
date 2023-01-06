// Day 7
// Task 1: https://bit.ly/3KcpHcB
// Date: 07-01-2023

// Time: 0(logN)
// Space: O(1)

int searchInSorted(int arr[], int N, int K) { 
    
       int start=0, end=N-1, mid;
       while(start<=end) {
           mid = start+(end-start)/2;
           
           if(arr[mid] == K) return 1;
           if(arr[mid] > K) end = mid-1;
           else start = mid+1;
       }
       return -1;
}
