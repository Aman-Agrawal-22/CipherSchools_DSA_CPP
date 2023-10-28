#include <bits/stdc++.h>
using namespace std;

//find the triplet that sum to a given value
//Two-Pointer's approach
//TC = O(n^2), SC = O(1)
bool triplet(vector<int>&v, int x) {
   sort(v.begin(), v.end());
   for (int i=0; i<v.size(); i++) {
        int y = x - v[i];
        int low = i+1, high = v.size() - 1;
        while (low < high) {
            if (v[low] + v[high] == y) return 1;
            else if (v[low] + v[high] > y) high--;
            else low++;
        }
   }
   return 0;
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
    int target;
    cout<<"Enter the target sum to find: ";
    cin>>target;
    if (triplet(v, target)) cout<<"Triplet sum found";
    else cout<<"No triplet exists in the array whose sum is equal to the target";
    return 0;
}
