#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
int maxLength(vector<int>& nums){
int n=nums.size();
int presum=0;
int maxi=0;
unordered_map<int,int> mpp;

for(int i=0;i<n;i++){
presum+=nums[i];

if(presum==0){
maxi=i+1;
}

if(mpp.find(presum)!=mpp.end()){
maxi=max(maxi,i-mpp[presum]);
}
else{
mpp[presum]=i;
}
}

return maxi;
}
};

int main(){
int n;
cin>>n;

vector<int> nums(n);

for(int i=0;i<n;i++){
cin>>nums[i];
}

Solution obj;

cout<<obj.maxLength(nums);

return 0;
}