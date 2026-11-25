#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        if (n == 0) return ans;

        int leader = arr[n - 1];
        ans.push_back(leader);

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= leader) {
                leader = arr[i];
                ans.push_back(leader);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};

    Solution sol;
    vector<int> res = sol.leaders(arr);

    for (int val : res) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}