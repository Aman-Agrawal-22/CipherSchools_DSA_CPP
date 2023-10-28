#include <bits/stdc++.h>
using namespace std;

//find the minimum number of swaps required to bring all the numbers less than or equal to K together
//Sliding Window 
//TC = O(n), SC = O(1)

//arr = {2,1,5,6,3} and k = 3  output: 1
//arr= {2,7,9,5,8,7,4} and k = 6 outpu: 2
int minSwap(vector<int>&v, int k) {
    int count = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i] <= k) count++;
    }

    int bad = 0;
    for (int i=0; i<count; i++) {
        if (v[i] > k) bad++;
    }

    int ans = bad;
    for (int i=0, j = count; j<v.size(); i++, j++) {
        if (v[i] > k) bad--;
        if (v[j] > k) bad++;
        ans = min(ans, bad);
    } 
    return ans;
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
    int k;
    cout<<"Enter number where the minimum swaps should be done is less than it: ";
    cin>>k;
    cout<<"Minimum number of swaps needed: "<<minSwap(v, k);
    return 0;
}
