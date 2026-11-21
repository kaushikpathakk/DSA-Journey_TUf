#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rearrange(vector<int>& arr) {
        vector<int> pos, neg;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            } else {
                neg.push_back(arr[i]);
            }
        }

        if (pos.size() > neg.size()) {
            for (int i = 0; i < neg.size(); i++) {
                arr[2 * i] = pos[i];
                arr[2 * i + 1] = neg[i];
            }
            int index = neg.size() * 2;
            for (int i = neg.size(); i < pos.size(); i++) {
                arr[index] = pos[i];
                index++;
            }
        } else {
            for (int i = 0; i < pos.size(); i++) {
                arr[2 * i] = pos[i];
                arr[2 * i + 1] = neg[i];
            }
            int index = pos.size() * 2;
            for (int i = pos.size(); i < neg.size(); i++) {
                arr[index] = neg[i];
                index++;
            }
        }
    }
};

int main() {
    vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};

    Solution sol;
    sol.rearrange(arr);

    for (int x : arr) {
        cout << x << " "; // Output: 9 -2 4 -1 5 -5 0 -3 2
    }
    cout << "\n";

    return 0;
}