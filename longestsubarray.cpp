// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, long long k) {
//         map<long long, int> preSumMap;
//         long long sum = 0;
//         int maxi = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             sum += nums[i];
//             // if prefix sum itself equals k
//             if(sum == k) {
//                 maxi = max(maxi, i + 1);
//             }
//          long long rem = sum - k;
//             // if remaining prefix exists
//             if(preSumMap.find(rem) != preSumMap.end()) {
//                 int len = i - preSumMap[rem];
//                 maxi = max(maxi, len);
//             }
//             // store first occurrence only
//             if(preSumMap.find(sum) == preSumMap.end()) {
//                 preSumMap[sum] = i;
//             }
//         }
//         return maxi;
//     }
// };
// int main() {
//   int n;
//     cin >> n;
//     vector<int> nums(n);
//     for(int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }
//     long long k;
//     cin >> k;
//     Solution obj;
//     cout << obj.longestSubarray(nums, k);
//     return 0;
// }




// above is the brute force solution for non negative number adn optimal for the combined and the below is the optimal solution for non negative number



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestSubarray(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;

        long long sum = nums[0];

        int maxLen = 0;

        int n = nums.size();

        while(right < n) {

            // shrink window
            while(left <= right && sum > k) {

                sum -= nums[left];
                left++;
            }

            // check sum
            if(sum == k) {

                maxLen = max(maxLen, right - left + 1);
            }

            // move right
            right++;

            if(right < n) {
                sum += nums[right];
            }
        }

        return maxLen;
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

    cout << obj.longestSubarray(nums, k);

    return 0;
}
