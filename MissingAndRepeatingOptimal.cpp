#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        long long n = nums.size();

        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        long long S = 0, S2 = 0;

        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += 1LL * nums[i] * nums[i];
        }

        long long val1 = S - SN;            // x - y
        long long val2 = (S2 - S2N) / val1; // x + y

        long long x = (val1 + val2) / 2;    // Repeating
        long long y = x - val1;             // Missing

        return {(int)x, (int)y};
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};

    vector<int> ans = obj.findMissingRepeatingNumbers(nums);

    cout << "Repeating Number : " << ans[0] << endl;
    cout << "Missing Number   : " << ans[1] << endl;

    return 0;
}