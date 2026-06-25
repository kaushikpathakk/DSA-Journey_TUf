#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n <= 1) return arr; 
        
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            if (ans.empty() || arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]); 
            }
            else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
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
    
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        arr.push_back({start, end});
    }
    
    Solution obj; 
    vector<vector<int>> mergedIntervals = obj.mergeOverlap(arr);
    
    for (int i = 0; i < mergedIntervals.size(); i++) {
        cout << "[" << mergedIntervals[i][0] << ", " << mergedIntervals[i][1] << "] ";
    }
    cout << endl;

    return 0;
}