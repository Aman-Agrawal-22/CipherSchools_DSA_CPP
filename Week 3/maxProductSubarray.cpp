#include <bits/stdc++.h>
using namespace std;

//Given an array that contains n integers(may be positive, negative or zero).
//find the product of the maximum product subarray.
//TC = O(n), SC = O(1)

//N = 5, arr = [6,-3,-10,0,2] output: 180
//subarray with max product is 6,-3,-10 which gives 180.
//N = 6, arr = [2,3,4,5,-1,0] output: 120
//subarray with max product is 2,3,4,5 which gives 120.

long long int maxProductSubarray(vector<int>&arr, int n) {
    
    long long int maxp = INT_MIN, prod = 1;
    //iterating left to right to find maximum product
    for (int i=0; i<n; i++) {
        prod *= arr[i];
        maxp = max(maxp, prod);
        //if at some time our product comes 0, then reintialize it to 1, otherwise it will not give correct answer
        if (prod == 0) prod = 1;
    } 

    //iterating right to left to see whether the array has max product here
    prod = 1;
    for (int i=n-1; i>=0; i--) {
        prod *= arr[i];
        maxp = max(maxp, prod);
        if (prod == 0) prod = 1;
    }
    return maxp;
}

int main() {
    vector<int> arr;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    cout<<"Maximum Product of Subarray is: "<<maxProductSubarray(arr, n);
    return 0;
}
