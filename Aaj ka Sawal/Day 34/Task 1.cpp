// Day 34
// Task 1: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1 
// Date: 03-02-2023


// APPROACH: Sliding window
//   Store positions of the negative numbers so got in a container of size k, and update in every window
// Time Complexity: O(N)
// Space Complexity: O(K)
// where N is the size of vector
// where K is the size of set

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
    // to store positions of negative numbers
    set<int> negPos;
    // to store the answer
    vector<long long int> pos;
    
    // first window
    for(int i=0; i<k; i++)
        if(a[i] < 0)
            negPos.insert(i);   // if negative found, store position
    
    // if no negative found, answer for window is 0
    if(negPos.size() == 0)
        pos.emplace_back(0);
    // otherwise answer for window is first negative number
    else
        pos.emplace_back(a[*(negPos.begin())]); // as set contains position, we need to get element
    

    // continuation for other windows
    for(int i=1; i<=n-k; i++) {
        // if last number in previous window was negative, remove its position from the set
        if(a[i-1] < 0)
            negPos.erase(i-1);

        // if current last number is negative, store its position
        if(a[i+k-1] < 0)
            negPos.insert(i+k-1);
        
        // if there are no negative numbers in current window, answer is 0
        if(negPos.size() == 0)
            pos.emplace_back(0);
        // otherwise answer for window is first negative number
        else
            pos.emplace_back(a[*(negPos.begin())]);
    }
    
    // return vector of answers
    return pos;
}
