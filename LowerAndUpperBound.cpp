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