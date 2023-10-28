#include <bits/stdc++.h>
using namespace std;

//Next Permutation - rearrange numbers into the lexigraphically next greater permutation of numbers. 
//if such an arrangement is not possible, it must rearrange it as the lowest possible order
//use O(1) extra space

//nums = [1,2,3] output: [1,3,2]
//nums = [3,2,1] output: [1,2,3]
//nums = [1,1,5] output: [1,5,1]
//TC = O(n), SC = O(1) 
void nextPermutation(vector<int>&nums) {
    if (nums.size() == 1) return;

    int idx1;
    for (int i=nums.size()-2; i>=0; i--) {
        if (nums[i] < nums[i+1]) {
            idx1 = i;
            break;
        }        
    }
    //no next permutation possible, means(it is the largest number), then return lowest possible order 
    if (idx1 < 0) {
        reverse(nums.begin(), nums.end());
        return;
    } else {
        int idx2 = 0;
        for (int i=nums.size()-1; i>=0; i--) {
            if (nums[i] > nums[idx1]) {
                idx2 = i;
                break;
            }
        }
        swap(nums[idx1], nums[idx2]);
        reverse(nums.begin()+idx1+1, nums.end());
    }
}

int main() {
    vector<int> nums;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    nextPermutation(nums);
    for (auto i: nums) cout<<i<<" ";
    return 0;
}
