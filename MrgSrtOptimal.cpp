#include<iostream>
using namespace std;
class Solution {
    public :
    void swapgreater (long long arr1[] , long long arr2[] , int ind1 , int ind2 ){
        if(arr1[ind1] > arr2[ind2]){
            swap(arr1[ind1] , arr2[ind2]);
        }
    }
    void MergeSortWithoutSpace ( long long arr1[] , long long arr2[]  , int n , int m ){
     int gap = (n+m)/2 + (n+m)%2;
   
     while ( gap > 0){
  int left = 0; 
     int right = left + gap ;
     while( right < n+m){
        // array 1 , 2
   if ( left < n && right > m){
    swapgreater(arr1 , arr2 , left , right -n);
   }
   // array 2, 2
   else if( left >n && right <m){
swapgreater(arr1 , arr2 , left-n , right );
   }
   // array 1, 1
   else {
swapgreater(arr1 , arr2 , left , right );
   }
   left ++ ; right ++;
     }
     if ( gap ==1) break;
     else gap = gap/2 + gap % 2;
     }
     }
};
int main(){
    return 0;
}