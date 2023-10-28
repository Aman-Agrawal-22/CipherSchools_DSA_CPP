#include <bits/stdc++.h>
using namespace std;

//rearrange the array in alternating positive and negative items with O(1) extra space
//TC = O(n), SC = O(1)
void rearrange(int arr[], int n) {
    int i = -1;
    for (int j = 0; j < n; j++) {
        if (arr[j] < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    int pos = i + 1, neg = 0;

    // Alternating positive and negative items
    while (pos < n && neg < pos && arr[neg] < 0) {
        swap(arr[neg], arr[pos]);
        pos++;
        neg += 2;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rearrange(arr, n);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
