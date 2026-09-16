#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = n1 + n2;

        int ind2 = n / 2;
        int ind1 = ind2 - 1;

        int cnt = 0;
        int ind1el = -1, ind2el = -1;
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                if (cnt == ind1) ind1el = arr1[i];
                if (cnt == ind2) ind2el = arr1[i];
                cnt++;
                i++;
            } else {
                if (cnt == ind1) ind1el = arr2[j];
                if (cnt == ind2) ind2el = arr2[j];
                cnt++;
                j++;
            }
        }

        while (i < n1) {
            if (cnt == ind1) ind1el = arr1[i];
            if (cnt == ind2) ind2el = arr1[i];
            cnt++;
            i++;
        }

        while (j < n2) {
            if (cnt == ind1) ind1el = arr2[j];
            if (cnt == ind2) ind2el = arr2[j];
            cnt++;
            j++;
        }

        if (n % 2 == 1) {
            return (double)ind2el;
        }
        return (double)(ind1el + ind2el) / 2.0;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1, 3, 4, 7, 10};
    vector<int> arr2 = {2, 3, 6, 15};

    double ans = sol.median(arr1, arr2);

    cout << ans << endl;

    return 0;
}