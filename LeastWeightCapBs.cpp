#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int FindDays(const vector<int>& weights, int cap) {
        int load = 0; 
        int days = 1; // we did it becoz we know the loading start from day 1 not 0
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + load > cap) {
                days += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (FindDays(weights, mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    
    int n, days;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cin >> days;

    int minCapacity = sol.shipWithinDays(weights, days);

    cout << minCapacity << endl;

    return 0;
}