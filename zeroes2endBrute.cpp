#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroesBruteVariation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int zeroCount = 0;

        // Step 1: Push non-zeros to temp and count zeros
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                temp.push_back(nums[i]);
            }
        }

        // Step 2: Append 'zeroCount' zeros to temp
        while (zeroCount > 0) {
            temp.push_back(0);
            zeroCount--;
        }

        // Step 3: Copy modified temp back into original nums
        nums = temp;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution obj;
    obj.moveZeroesBruteVariation(nums);

    for (int x : nums) {
        cout << x << " ";
    }
    // Output: 1 3 12 0 0
    return 0;
}