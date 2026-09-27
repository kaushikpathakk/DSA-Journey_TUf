#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int upperbound(const vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0; int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > k) { 
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countsmallequal(const vector<vector<int>>& mat, int n, int m, int k) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperbound(mat[i], k);
        }
        return cnt;
    }

    int median(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX; int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }
        int req = (n * m) / 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int smallequal = countsmallequal(mat, n, m, mid);
            if (smallequal <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main() {
    Solution solver;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cout << solver.median(mat) << endl;

    return 0;
}