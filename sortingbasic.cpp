#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n - 2; i++) {
            int mini = i; 
            for(int j = i; j <= n - 1; j++) {
                if(nums[j] < nums[mini]) {
                    mini = j;
                }
            }
            swap(nums[i], nums[mini]); 
        }
        return nums; 
    }
  
    vector<int> Bubblesort(vector<int>&nums){
         int n = nums.size();
        
   for( int i = n-1 ; i>=1; i-- ){
     int no_swap = 0;
    for( int j =1; j<=i-1; j++){
        if(nums[j]>nums[j+1]){
            swap(nums[j], nums[j+1]);
            no_swap = 1;
            cout<<"runs";
        }
    }

    if(no_swap==0)
   {
  break;
   }
    }
     return nums;
}

    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n - 1; i++) {
            int j = i;
            // Jab tak piche wala element bada hai, swap karte raho
            while (j > 0 && nums[j - 1] > nums[j]) {
                swap(nums[j - 1], nums[j]);
                j--; // Piche move karo
            }
        }
        return nums;
    }
};


int main() {
   
    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
  //  vector<int> sortedNums = sol.selectionSort(nums);
    vector<int> sortedNums = sol. insertionSort(nums);

    for(int i = 0; i < n; i++) {
        cout << sortedNums[i] << " ";
    }

    return 0;
}