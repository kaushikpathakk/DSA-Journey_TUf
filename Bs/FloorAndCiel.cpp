#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        int floorVal = -1; 
        int ceilVal = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return {nums[mid], nums[mid]};
            } 
            else if (nums[mid] < target) {
                floorVal = nums[mid];
                low = mid + 1;
            } 
            else {
                ceilVal = nums[mid];
                high = mid - 1;
            }
        }

        return {floorVal, ceilVal};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.getFloorAndCeil(nums, target);

    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << "\n";

    return 0;
}