
#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
int partition( vector<int>&nums ,  int low  ,int  high ){
    int pivot = nums[low];
    int i = low ;
    int j = high ;
    while( i< j){
         while( nums[i]<= pivot  && i <= high  - 1 ){
            i++;
         }
         while( nums[j]> pivot && j>= low +1){
            j--;
         }
         if(i<j)  swap( nums[i], nums[j]);
    }
    swap( nums[low], nums[j]);
    return j;
}
void qs( vector <int>& nums , int low  ,int high ){
    if( low  < high ){
 int pIndex = partition( nums , low  , high );
 qs( nums , low , pIndex -1 );
 qs( nums , pIndex +1 , high);
    }
}
    vector<int> quickSort(vector<int>& nums) {
   qs( nums , 0 ,  nums.size()-1);
   return nums;
    }
};
int main() {
    // Input size lelo
    int n;
    cout << "Array ka size daalo: ";
    if (!(cin >> n)) return 0;

    // Array (vector) mein elements bharo
    vector<int> nums(n);
    cout << n << " elements daalo: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Solution class ka object banao
    Solution sol;
    
    // Quick Sort call karo
    vector<int> sortedNums = sol.quickSort(nums);

    // Sorted array print karo
    cout << "Sorted Array ye raha bhai: " << endl;
    for(int i = 0; i < n; i++) {
        cout << sortedNums[i] << " ";
    }
    cout << endl;

    return 0;
}