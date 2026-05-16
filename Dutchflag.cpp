#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void sortZeroOneTwo(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        while(mid <= high) {

            // if element is 0
            if(nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            // if element is 1
            else if(nums[mid] == 1) {

                mid++;
            }

            // if element is 2
            else {

                swap(nums[mid], nums[high]);

                high--;
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

    obj.sortZeroOneTwo(nums);

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}