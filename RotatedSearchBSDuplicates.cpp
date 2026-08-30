#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0; 
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) return true;

            // Handle duplicate boundary elements
            if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
                low += 1;
                high -= 1;
                continue;
            }

            // Left half is sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= key && key <= arr[mid]) {
                    high = mid - 1;
                } else { 
                    low = mid + 1; 
                }
            }
            // Right half is sorted
            else {
                if (arr[mid] <= key && key <= arr[high]) {
                    low = mid + 1;
                } else { 
                    high = mid - 1; 
                }
            }
        }
        
        return false;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, key;
    if (!(cin >> n >> key)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    bool found = obj.search(arr, key);

    if (found) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}