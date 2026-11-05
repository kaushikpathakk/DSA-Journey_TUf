#include <bits/stdc++.h>
using namespace std;

class Solution {
    int bs(vector<int>& arr, int low, int high, int target) {
        if (low > high) return -1;

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            return bs(arr, low, mid - 1, target);
        } else {
            return bs(arr, mid + 1, high, target);
        }
    }

public:
    int FirstSearch(vector<int>& arr, int target) {
        return bs(arr, 0, arr.size() - 1, target);
    }
};

int main() {
    Solution sol;
    int n, target;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    int index = sol.FirstSearch(arr, target);

    if (index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}