#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstO(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1; 
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // Keep looking on the left
            }
            else if (nums[mid] > target) {
                high = mid - 1;   
            }
            else { 
                low = mid + 1;
            }
        }
        return first;
    }

    int lastO(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1; 
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1; // Keep looking on the right
            }
            else if (nums[mid] > target) {
                high = mid - 1;   
            }
            else { 
                low = mid + 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int first = firstO(nums, target); // Fixed: removed extra 'int' keyword
        if (first == -1) return {-1, -1};
        
        int last = lastO(nums, target);  // Fixed: removed extra 'int' keyword
        return {first, last};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    if (!(cin >> n >> target)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.searchRange(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]\n";

    return 0;
}