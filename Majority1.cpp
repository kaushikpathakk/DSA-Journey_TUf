#include <bits/stdc++.h>
using namespace std;
int Majority(vector<int> a) {
    int n = a.size();
    int cnt = 0;
    int ele;
    for(int i = 0; i < n; i++) {
        if(cnt == 0) {
            cnt = 1;
            ele = a[i];
        }
      else if(a[i] == ele) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == ele) {
            cnt1++;
        }
    }
    if(cnt1 > n / 2) {
        return ele;
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
 vector<int> a(n);
    for(int i = 0; i < n; i++) {
    cin >> a[i];
    }
    cout << Majority(a);
    return 0;
}