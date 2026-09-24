#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:   
    int lowerBound(const vector<int>& arr, int n, int x) {
        int low = 0; 
        int high = n - 1;
        int ans = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        return ans;
    }

    int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size();
        int cnt_max = 0; 
        int index = -1;
        
        for (int i = 0; i < n; i++) {
            int cnt_ones = m - lowerBound(mat[i], m, 1);
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

int main() {
    Solution sol;

    // Example 2D Matrix (Sorted rows containing only 0s and 1s)
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int result = sol.rowWithMax1s(mat);

    if (result != -1) {
        cout << "Row with maximum 1s is: " << result << endl;
    } else {
        cout << "No 1s found in the matrix." << endl;
    }

    return 0;
}