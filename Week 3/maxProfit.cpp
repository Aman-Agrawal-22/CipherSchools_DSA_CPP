#include <bits/stdc++.h>
using namespace std;

//maximum profit by buying and selling a share atmost twice
//Buy->sell->Buy->sell
//arr = [10,22,5,75,65,80] output: 87 
//as buy on 10 and sell on 22 (profit = 12) and then buy on 5 and sell on 80(profit = 75)
//totalprofit = 87(which is maximum profit)
//TC = O(n), SC = O(1)

int maxProfit(vector<int>&price) {
    vector<int> profit(price.size(), 0);
    
    int max_price = price[price.size() - 1];
    for (int i= price.size()-2; i>=0; i--) {
        if (price[i] > max_price) max_price = price[i];
        profit[i] = max(profit[i+1], max_price - price[i]);
    }

    int min_price = price[0];
    for (int i=1; i<price.size(); i++) {
        if (price[i] < min_price) min_price = price[i];
        profit[i] = max(profit[i-1], profit[i] + (price[i] - min_price));
    }

    int result = profit[price.size()-1];
    return result;

}

int main() {
    vector<int> price;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int val;
        cin>>val;
        price.push_back(val);
    }
    cout<<"Maximum Profit: "<<maxProfit(price);
    return 0;
}
