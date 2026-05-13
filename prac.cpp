#include<iostream>
using namespace std;
void reversenumber(int n){
    int original = n;
    while(n>0){
        int ld = n % 10 ;
        cout<<ld;
        n = n/10;
    }
}
int main (){
    int n;
    cin>>n;
    reversenumber(n);
    return 0;
}