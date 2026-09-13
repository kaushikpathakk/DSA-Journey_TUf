#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countStudents(const vector<int> &nums, int pages) {
        int students = 1;
        int studentPages = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (studentPages + nums[i] <= pages) {
                studentPages += nums[i];
            } else {
                students++;
                studentPages = nums[i];
            }
        }
        return students;
    }

    int findPages(vector<int> &nums, int m) {
        int n = nums.size();

        if (m > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countStudents(nums, mid) > m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int ans = sol.findPages(books, students);
    cout << ans << endl;

    return 0;
}