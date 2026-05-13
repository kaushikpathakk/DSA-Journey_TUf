#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<" enter the number of element in array arr"<<endl;
    cin>>n;
    int arr[n];
    cout<<" Ab un array mai number bhr "<<endl;
    for( int i =0; i<n ; i++){
        cin>>arr[i];
    }
    //hashing
int hash[13] = {0};
for(int i=0; i<n; i++){
    hash[arr[i]] += 1;
}

    int q;
    cout<<" Q ki bari"<<endl;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
    return 0;
}