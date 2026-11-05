#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ThreeSum(vector<int> &v)
    {
        int n = v.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            set<int> hashst;
            for (int j = i + 1; j < n; j++)
            {
                int third = -(v[i] + v[j]);
                if (hashst.find(third) != hashst.end())
                {
                    vector<int> temp = {v[i], v[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashst.insert(v[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution obj;
    vector<vector<int>> ans = obj.ThreeSum(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// this is not the optimal solution but a better way to think