#include <bits/stdc++.h>
using namespace std;

//given an array of intervals, where intervals[i] = [start(i), end(i)], merge all overlapping intervals
//return an array of the non-overlapping intervals that cover all the intervals in the input
//TC = O(n), SC = O(1)

//intervals = {{1,3}, {2,6}, {8,10}, {15,18}} output: {{1,6}, {8,10}, {15,18}}
//since intervals {1,3} and {2,6} overlaps, merge them into {1,6}.

//intervals = {{1,4}, {4,5}} output: {{1,5}}
//intervals {1,4} and {4,5} are considered overlapping.

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if (intervals.size() == 0) return res;
    
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });
    
    vector<int> curr = intervals[0];
    
    for (int i = 1; i < intervals.size(); i++) {
        if (curr[1] < intervals[i][0]) {
            res.push_back(curr);
            curr = intervals[i];
        } else {
            curr[1] = max(curr[1], intervals[i][1]);
        }
    }
    
    res.push_back(curr);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals;

    for (int i = 0; i < n; i++) {
        vector<int> interval(2);
        for (int j = 0; j < 2; j++) {
            int val;
            cin >> val;
            interval[j] = val;
        }
        intervals.push_back(interval);
    }

    vector<vector<int>> vec = mergeIntervals(intervals);
    
    for (auto i : vec) {
        for (auto e : i) {
            cout << e << " ";
        }
        cout << endl;
    }
    
    return 0;
}
