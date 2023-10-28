#include <bits/stdc++.h>
using namespace std;

//sort an array of 0's, 1's and 2's without using sorting algo
//TC = O(n), SC = O(1)
void sortarr(vector<int>&v) {
    int l=0, m=0, h=v.size()-1;
    while (m <= h) {
        if (v[m] == 1) m++;
        else if (v[m] == 0) {
            swap(v[m], v[l]);
            m++;
            l++;
        }
        else {
            swap(v[m], v[h]);
            h--;
        }
    }
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
    sortarr(v);
    for (auto i: v) cout<<i<<" ";
    return 0;
}
