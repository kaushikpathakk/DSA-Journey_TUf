#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0; int high = (m * n) - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            int row = mid / m; int col = mid % m;
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        } 
        return false;
    }
};

int main() {
    Solution solver;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    if (solver.searchMatrix(matrix, target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}