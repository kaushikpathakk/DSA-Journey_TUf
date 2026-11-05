
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        
        // Single element array edge case
        if (n == 1) return nums[0];
        
        // Boundary checks
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1; 
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Found the unique element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // We are on the left side of the single element -> target is on the right half
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || 
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            }
            // We are on the right side of the single element -> target is on the left half
            else {
                high = mid - 1;
            }
        }   
        return -1;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter size of vector (odd number): ";
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    cout << "Enter " << n << " sorted elements (every element twice except one): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.singleNonDuplicate(nums);

    cout << "Single element is: " << result << "\n";

    return 0;
}

