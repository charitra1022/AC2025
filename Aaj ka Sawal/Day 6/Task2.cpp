// Task 2:
// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
// Date: 06-01-2023

// Time Complexity: O(m+n)
// Space complexity: O(m+n)

class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        set<int> st;
        for(int i=0; i<n; i++)
            st.emplace(arr1[i]);
        for(int i=0; i<m; i++)
            st.emplace(arr2[i]);
        return vector<int>(st.begin(), st.end());
    }
