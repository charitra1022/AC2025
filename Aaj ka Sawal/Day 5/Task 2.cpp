// Task 2: 
// https://practice.geeksforgeeks.org/problems/replace-all-0s-with-5/1
// Date: 05-01-2023

// Time: O(logK)
// Space: O(1) 

int numberOfDigits(int n) {
    // Returns nnumber of digits

    int d = 0;
    while(n > 0) {
        d++;
        n /= 10;
    }
    return d;
}

int convertFive(int n) {
    int d = numberOfDigits(n);
    d--;

    int newN = 0; // store new number

    while(d >= 0) {
        int digit = n/(int)pow(10, d);  // get digits from he start
        
        if(digit == 0) digit = 5;   // replace the digit by 5 if 0 found

        newN = digit*pow(10, d) + newN; // create the new number

        n = n%(int)pow(10, d);  // remove the digit from the start
        d--;  // decrement the number of digits remaining to be traversed
    }
    return newN;
}
