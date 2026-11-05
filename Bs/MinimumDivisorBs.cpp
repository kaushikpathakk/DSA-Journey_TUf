#include <iostream>
#include <vector>
#include <algorithm>
// #include <cmath>

using namespace std;

class Solution {
public:
    int SumOfDiv(const vector<int>& nums, int div) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + div - 1) / div;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n > limit) return -1;
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (SumOfDiv(nums, mid) <= limit) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n, limit;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> limit;

    int ans = sol.smallestDivisor(nums, limit);

    cout << ans << endl;

    return 0;
}