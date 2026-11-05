#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countHour(const vector<int>& nums, int s) {
        long long totalHour = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalHour += (nums[i] + s - 1) / s;
        }
        return totalHour;
    }

    int minimumRateToEatBananas(vector<int>& nums, int h) {
        int n = nums.size();
        int maxi = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > maxi) maxi = nums[i];
        }

        int low = 1, high = maxi;
        int ans = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long output = countHour(nums, mid);

            if (output <= h) {
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
    
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int minSpeed = sol.minimumRateToEatBananas(piles, h);

    cout << "Minimum Eating Speed: " << minSpeed << endl;

    return 0;
}