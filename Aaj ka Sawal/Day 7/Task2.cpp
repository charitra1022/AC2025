// Day 7
// Task 2: https://bit.ly/3A2pKTh
// Date: 07-01-2023

// Time: O(N)
// Space: O(1)


int missingNumber(int A[], int N){
    // Store sum of all numbers from 1-N
    int finalSum = N*(N+1)/2;

    // Store sum of all numbers in array
    int curSum = 0;
    
    for(int i=0; i<N-1; i++)
        curSum += A[i];
    
    // Number missing is not in curSum
    return finalSum - curSum;
}
