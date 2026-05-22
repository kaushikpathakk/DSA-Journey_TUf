#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
      int n = matrix.size();
      for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
          if(i != j){
            swap(matrix[i][j], matrix[j][i]);
          }
        }
      } 
      for(int i = 0; i < n; i++){
         reverse(matrix[i].begin(), matrix[i].end());
      }
    }
};
int main() {
    Solution sol;
    int n;
    cout << "Enter the size of the square matrix (N x N): ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    sol.rotateMatrix(matrix);
    cout << "Rotated Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}