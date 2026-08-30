#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int k) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == k) return mid;

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= k && k <= nums[mid]) {
                    high = mid - 1;
                } else { 
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= k && k <= nums[high]) {
                    low = mid + 1;
                } else { 
                    high = mid - 1;
                }
            }
        }  
        return -1;
    }
};
// time complexity is O(logn)( base is 2)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter size of vector: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (rotated sorted array): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter target element (k): ";
    cin >> k;

    Solution obj;
    int result = obj.search(nums, k);

    if (result != -1) {
        cout << "Element " << k << " found at index: " << result << "\n";
    } else {
        cout << "Element " << k << " not found in the array.\n";
    }

    return 0;
}