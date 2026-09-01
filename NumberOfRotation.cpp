#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int NumberOfRotation(vector<int> &nums) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        
        // Initialize minIndex to 0 (valid index) and minVal to infinity
        int minIndex = 0;
        int minVal = INT_MAX;

        while (low <= high) {
            // Case 1: Entire range is already sorted
            if (nums[low] <= nums[high]) {
                if (nums[low] < minVal) {
                    minVal = nums[low];
                    minIndex = low;
                }
                break;
            }

            int mid = low + (high - low) / 2;

            // Case 2: Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] < minVal) {
                    minVal = nums[low];
                    minIndex = low;
                }
                low = mid + 1; // Minimum must be in unsorted right half
            } 
            // Case 3: Right half is sorted
            else {
                if (nums[mid] < minVal) {
                    minVal = nums[mid];
                    minIndex = mid;
                }
                high = mid - 1; // Minimum must be in unsorted left half
            }
        }

        return minIndex;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter array size: ";
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int rotations = obj.NumberOfRotation(nums);

    cout << "Array is rotated " << rotations << " times.\n";

    return 0;
}