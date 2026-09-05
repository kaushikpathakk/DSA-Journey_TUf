#include <iostream>
using namespace std;
class Solution {
public:
    int NthRoot(int N, int M) {
        if (M == 0) return 0;

        int low = 1;
        int high = M;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long val = 1;
            for (int i = 0; i < N; i++) {
                val *= mid;
                if (val > M) {
                    break;
                }
            }

            if (val == M) {
                return mid;
            }

            if (val < M) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    cout << sol.NthRoot(4, 16) << "\n";
cout << sol.NthRoot(3, 14) << "\n";
    cout << sol.NthRoot(2, 0) << "\n";
    cout << sol.NthRoot(3, 27) << "\n"
;    return 0;
}