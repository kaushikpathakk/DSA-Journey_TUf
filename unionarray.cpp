#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;

        vector<int> unionArr;

        while(i < n1 && j < n2) {

            if(nums1[i] <= nums2[j]) {

                if(unionArr.size() == 0 || unionArr.back() != nums1[i]) {
                    unionArr.push_back(nums1[i]);
                }

                i++;
            }

            else {

                if(unionArr.size() == 0 || unionArr.back() != nums2[j]) {
                    unionArr.push_back(nums2[j]);
                }

                j++;
            }
        }

        while(i < n1) {

            if(unionArr.size() == 0 || unionArr.back() != nums1[i]) {
                unionArr.push_back(nums1[i]);
            }

            i++;
        }

        while(j < n2) {

            if(unionArr.size() == 0 || unionArr.back() != nums2[j]) {
                unionArr.push_back(nums2[j]);
            }

            j++;
        }

        return unionArr;
    }
};

int main() {

    int n1;
    cin >> n1;

    vector<int> nums1(n1);

    for(int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    int n2;
    cin >> n2;

    vector<int> nums2(n2);

    for(int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    Solution obj;

    vector<int> result = obj.unionArray(nums1, nums2);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}