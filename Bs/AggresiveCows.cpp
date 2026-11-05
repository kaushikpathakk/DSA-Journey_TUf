#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool Canweplace(vector<int>& nums, int dist, int cows) {
        int cntCows = 1; 
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - last >= dist) {
                cntCows++;
                last = nums[i];
            }
            if (cntCows >= cows) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1; 
        int high = nums[n-1] - nums[0]; 

        while (low <= high) {
            int mid = low + (high - low) / 2; // integer overflow safe formulation
            if (Canweplace(nums, mid, k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main() {
    Solution sol;

    // Test Case: Stall positions and number of cows (k)
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    int result = sol.aggressiveCows(stalls, k);

    cout << "Maximum minimum distance is: " << result << endl;

    return 0;
}