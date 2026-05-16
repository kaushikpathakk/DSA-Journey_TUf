#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int moreNeeded = target - nums[i];
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> target;

    Solution obj;
    vector<int> result = obj.twoSum(nums, target);

    if (!result.empty()) {
        cout << result[0] << " " << result[1] << endl;
    }
    
    return 0;
}