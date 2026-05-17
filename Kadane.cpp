#include <bits/stdc++.h>
using namespace std;
class Solution {
public :
    int maxSubArray(vector<int>& nums) {
        long long sum = 0;
        long long maxi = LLONG_MIN;
        int start = 0;
        int ansStart = 0;
        int ansEnd = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum == 0) {
                start = i;
            }
            sum += nums[i];
            if(sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0) {
                sum = 0;
            }
        }
        cout << "Maximum Subarray: ";
        for(int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return maxi;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    int ans = obj.maxSubArray(nums);
    cout << "Maximum Sum: " << ans;
    return 0;
}