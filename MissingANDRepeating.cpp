#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<int> MissingANDRepeating(vector<int>& nums){
int n=nums.size();

int arr[n+1]={0};

for(int i=0;i<n;i++){
arr[nums[i]]++;
}

int missing=-1;
int repeating=-1;

for(int i=1;i<=n;i++){
if(arr[i]==2){
repeating=i;
}
else if(arr[i]==0){
missing=i;
}
}

return {repeating,missing};
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

vector<int> ans=obj.MissingANDRepeating(nums);

cout<<ans[0]<<" "<<ans[1];

return 0;
}
