#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxColIndex(const vector<int>& row) {
        int m = row.size();
        int max_val = -1;
        int col_idx = -1;
        for (int j = 0; j < m; j++) {
            if (row[j] > max_val) {
                max_val = row[j];
                col_idx = j;
            }
        }
        return col_idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) >> 1;
            int max_col = findMaxColIndex(mat[mid]);

            int up = (mid - 1 >= 0) ? mat[mid - 1][max_col] : -1;
            int down = (mid + 1 < n) ? mat[mid + 1][max_col] : -1;

            if (mat[mid][max_col] > up && mat[mid][max_col] > down) {
                return {mid, max_col};
            }
            else if (mat[mid][max_col] < up) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
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

    vector<int> peak = solver.findPeakGrid(mat);

    cout << peak[0] << " " << peak[1] << endl;

    return 0;
}