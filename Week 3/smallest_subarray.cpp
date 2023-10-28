#include <bits/stdc++.h>
using namespace std;

//smallest subarray with sum greater than a given value
//TC = O(n), SC = O(1)
int shortestSubarray(vector<int>&v, int x) {
    int n = v.size();
    int curr_sum = 0, min_len = n + 1;
    int start = 0, end = 0;
    while (end < n) {
        while (curr_sum <= x && end < n) curr_sum += v[end++];
        while (curr_sum > x && start < n) {
            if (end - start < min_len) min_len = end - start;
            curr_sum -= v[start++];
        }
    }
    return min_len;
}

int main() {
    vector<int> v;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int val;
        cin>>val;
        v.push_back(val);
    }
    int x;
    cout<<"Enter target to find the smallest subarray whose sum is greater than target: ";
    cin>>x;
    cout<<"Min length required: "<<shortestSubarray(v, x);
    return 0;
}
