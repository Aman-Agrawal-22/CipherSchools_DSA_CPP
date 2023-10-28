#include <bits/stdc++.h>
using namespace std;

//Given an array arr[] where each element represents the max number of steps that can be made forward from that index. 
//The task is to find the minimum number of jumps to reach the end of the array starting from index 0.
//TC = O(n), SC = O(1)

// Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
// Output: 3 (1-> 3 -> 9 -> 9)
// Explanation: Jump from 1st element to 2nd element as there is only 1 step.
// Now there are three options 5, 8 or 9. If 8 or 9 is chosen then the end node 9 can be reached. So 3 jumps are made.

// Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// Output: 10
// Explanation: In every step a jump is needed so the count of jumps is 10.

int minJumps(vector<int>&v, int n) {

    //it means we are already on our last element
    if (n <=1 ) return 0;
    
    //since first element is 0 which means we can never reach end
    if (v[0] == 0) return -1;
    
    int maxReach = v[0];
    int step = v[0];
    int jump = 1;

    int i = 1;
    for (i = 1; i<n; i++) {
        if (i == n - 1) return jump;
        maxReach = max(maxReach, i + v[i]);
        step--;
        if (step == 0) {
            jump++;
            if (i >= maxReach) return -1;
            step = maxReach - i;
        }
    }
    return -1;

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
    cout<<"Minimumum jumps to reach the last element: "<<minJumps(v, n);
    return 0;
}
