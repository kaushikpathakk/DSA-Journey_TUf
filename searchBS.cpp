#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int firstSearch(vector<int> &arr, int k) {
        int n = arr.size();
        int low = 0; 
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            
            if (arr[mid] == k) return mid;
            else if (arr[mid] < k) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);  // for faster use of cout and cin 
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    Solution obj;
    int result = obj.firstSearch(arr, k);

    cout << result << endl;

    return 0;
}