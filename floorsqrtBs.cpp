#include<iostream>
using namespace std;
class Solution {
    public :
    int FloorSqrt ( int n ){
     if(n < 0) return -1;
     if( n == 0 || n == 1){
        return n;
     }
     int low = 1;
     int high = n ;
     while(low <=high){
        long long mid = (high + low)/2;
        long long val = (mid*mid);
        if(val <= n){
            low = mid + 1;
        }
        else {
            high = mid -1;
        }
     }
     return high ;
    }
};
int main(){
     int n ; 
     cout<<" Enter the number "<<endl;
     cin>>n;
      Solution obj;
     int result = obj.FloorSqrt(n);
    cout<<result<<endl;
    return 0;
}