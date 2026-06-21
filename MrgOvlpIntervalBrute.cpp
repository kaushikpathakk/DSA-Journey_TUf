#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<vector<int>> mergeoverlappingintervalBRUTE(vector<vector<int>>& nums){
int n=nums.size();

sort(nums.begin(),nums.end());

vector<vector<int>> ans;

for(int i=0;i<n;i++){

int start=nums[i][0];
int end=nums[i][1];

if(!ans.empty() && end<=ans.back()[1]){
continue;
}

for(int j=i+1;j<n;j++){
if(nums[j][0]<=end){
end=max(end,nums[j][1]);
}
else{
break;
}
}

ans.push_back({start,end});
}

return ans;
}
};

int main(){

int n;
cin>>n;

vector<vector<int>> temp(n,vector<int>(2));

for(int i=0;i<n;i++){
for(int j=0;j<2;j++){
cin>>temp[i][j];
}
}

Solution obj;

vector<vector<int>> ans=obj.mergeoverlappingintervalBRUTE(temp);

for(int i=0;i<ans.size();i++){
cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
}

return 0;
}