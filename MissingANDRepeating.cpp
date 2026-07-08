#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    vector<int>MissingANDRepeating (vector<int>&nums){
        int n = nums.size();
       int arr [n+1] = {0};
       for( int i = 0; i< n ; i++){
        arr[nums[i]]++;
       }
       int missing = -1;
       int repeating = -1;
       for( int i = 0; i< n; i++){
       if ( arr[i] == 2){
        repeating = i;
       }
       else if ( arr[i] == 0){
        missing = i;
       }
       }
       return {repeating , missing };
    }
};
int main(){
    int n ;
    cin>>n;
    vector<int>nums;
    for( int i = 0; i< n; i++)
    return 0;
}