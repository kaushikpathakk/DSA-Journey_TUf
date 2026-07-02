#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& n1, int n, vector<int>& n2, int m) {

        vector<int> arr(n + m);

        int left = 0, right = 0, index = 0;

        while(left < n && right < m){
            if(n1[left] <= n2[right])
                arr[index++] = n1[left++];
            else
                arr[index++] = n2[right++];
        }

        while(left < n)
            arr[index++] = n1[left++];

        while(right < m)
            arr[index++] = n2[right++];

        for(int i = 0; i < n + m; i++){
          if( i < n ) n1[i] = arr[i];
          else n2[i-n] = arr[i];
    }}
};

#include <bits/stdc++.h>
using namespace std;

int main() {

    Solution obj;

    vector<int> n1 = {1, 3, 5};
    vector<int> n2 = {2, 4, 6};

    int n = n1.size();
    int m = n2.size();

    obj.merge(n1, n, n2, m);

    cout << "First Array : ";
    for(int x : n1)
        cout << x << " ";

    cout << "\nSecond Array : ";
    for(int x : n2)
        cout << x << " ";

    return 0;
}