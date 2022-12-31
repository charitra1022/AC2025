// Link: https://practice.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/0

// Time Complexity: O(N)
// Space Complexity: O(1)

vector<int> minAnd2ndMin(int a[], int n) {
    if(n == 1) return vector<int> {-1, -1};
    
    int smallest = a[0], largest = a[0];
    for(int i=0; i<n; i++){
        if(smallest > a[i]) smallest = a[i];
        if(largest < a[i]) largest = a[i];
    }
        
        
    int secondSmallest = largest;
    for(int i=0; i<n; i++) {
        if(a[i] < secondSmallest && a[i] > smallest) secondSmallest = a[i];
    }
    
    if(smallest == secondSmallest) return vector<int> {-1};
    return vector<int> {smallest, secondSmallest};
}
