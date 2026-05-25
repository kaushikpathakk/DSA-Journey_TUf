#include<bits\stdc++.h>
using namespace std;
vector<int>GenerateRow( int row){
vector<int>ansRow;
int res = 1;
ansRow.push_back(1);
for(int col = 1; col < row; col++){
    res = res*(row - col);
    res = res/col;
    ansRow.push_back(res);
}
return ansRow;
}
vector<vector<int>>PascalTriangle( int N){
    vector<vector<int>>ans;
    for( int i = 0; i< N; i++){
        ans.push_back(GenerateRow(i+1));
    }
return ans;
}
int main(){
int n;
cin>>n;
vector<vector<int>>ans = PascalTriangle(n);
for(int i=0;i<n;i++){
for(int j=0;j<ans[i].size();j++){
cout<<ans[i][j]<<" ";
}
cout<<endl;
}
return 0;
}