#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        cout << it.first << " -> " << it.second << endl;
    }

    int q;
    cin >> q;

    while(q--){
        int numbers;
        cin >> numbers;
        cout << mpp[numbers] << endl;
    }

    return 0;
}