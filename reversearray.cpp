#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void reverse(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotateArray(vector<int>& nums, int k) {

        int n = nums.size();

        if(n == 0) return;

        k = k % n;

        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
        reverse(nums, 0, n - 1);
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution obj;
    obj.rotateArray(nums, k);

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
/* This is the optimal solution of reversing the array by given places 
TIME complexity is 0{2n}
SPACE complexity if 0[0]

 to right rotate the array 
class Solution {
public:

    void reverse(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotateArray(vector<int>& nums, int k) {

        int n = nums.size();

        if(n == 0) return;

        k = k % n;

        // STEP 1: reverse full array
        reverse(nums, 0, n - 1);

        // STEP 2: reverse first k elements
        reverse(nums, 0, k - 1);

        // STEP 3: reverse remaining
        reverse(nums, k, n - 1);
    }
};


*/


