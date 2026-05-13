#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
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
    obj.moveZeroes(nums);

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}