#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(const vector<int>& nums, int days, int k, int m) {
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= days) {
                cnt++;
            } else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }

    int roseGarden(int n, vector<int> nums, int k, int m) {
        if ((long long)n < (long long)k * m) return -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        int low = mini;
        int high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(nums, mid, k, m)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    
    int n, m, k;
    cout << "Enter array size (n), bouquets needed (m), flowers per bouquet (k): ";
    cin >> n >> m >> k;

    vector<int> nums(n);
    cout << "Enter " << n << " bloom day values: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = sol.roseGarden(n, nums, k, m);

    cout << "Minimum days required: " << ans << endl;

    return 0;
}