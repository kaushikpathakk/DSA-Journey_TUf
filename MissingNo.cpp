#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

    int MissingNumber(vector<int> nums) {

        int n = nums.size();

        int actualsum = n * (n + 1) / 2;

        int numsum = 0;

        for(int i = 0; i < n; i++) {
            numsum += nums[i];
        }

        return actualsum - numsum;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution S;

    cout << S.MissingNumber(nums);

    return 0;
}