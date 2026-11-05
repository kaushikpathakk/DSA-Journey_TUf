#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LowerBound(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        int ans = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] >= target) {  // Upper bound mai bus isi lione mai "=" ko hta do
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.LowerBound(nums, target);
    cout << result << "\n";

    return 0;
}


// Below code is very important fro the COMPETITIVE PROGRAMMING 

// #include <iostream>
// #include <vector>
// #include <algorithm> // Required header

// using namespace std;

// int main() {
//     vector<int> nums = {1, 3, 5, 5, 5, 8, 10};
//     int target = 5;

//     // 1. Get lower bound index (>= 5) -> Index 2 (value 5)
//     int lb_idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

//     // 2. Get upper bound index (> 5) -> Index 5 (value 8)
//     int ub_idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

//     cout << "Lower Bound Index: " << lb_idx << "\n";
//     cout << "Upper Bound Index: " << ub_idx << "\n";

//     return 0;
// } this is the predefinend stl for the upper and lower bound in cpp