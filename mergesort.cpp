#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Do sorted arrays ko merge karne ka function
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;      
        int right = mid + 1; 

        // Dono halves mein se chota element uthao
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Agar left side mein kuch bacha hai
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Agar right side mein kuch bacha hai
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Temp se wapas original array mein copy karo
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mSort(vector<int>& nums, int low, int high) {
        if (low >= high) return; // Base Case: Jab ek hi element bacha ho

        int mid = (low + high) / 2;
        
        mSort(nums, low, mid);      // Left half ko todna
        mSort(nums, mid + 1, high);  // Right half ko todna
        
        merge(nums, low, mid, high); // Merge karke sort karna
    }

    vector<int> sortArray(vector<int>& nums) {
        mSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    sol.sortArray(nums);

    for(int i = 0; i < n; i++) cout << nums[i] << " ";
    
    return 0;
}