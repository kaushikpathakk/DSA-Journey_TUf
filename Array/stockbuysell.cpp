#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int stockBuySell(vector<int> &arr, int n)
  {
    int mini = arr[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
      int cost = arr[i] - mini;
      profit = max(profit, cost);
      mini = min(mini, arr[i]);
    }
    return profit;
  }
};
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  Solution obj;
  cout << obj.stockBuySell(arr, n);
  return 0;
}
// class Solution {
//   public:
//     int maxProfit(vector<int> &prices) {
//         int profit = 0;
//         for (int i = 1; i < prices.size(); i++) {
//             if (prices[i] > prices[i - 1]) {
//                 profit += (prices[i] - prices[i - 1]);
//             }
//         }
//         return profit;
//     }
// };    this is when we can sell multiple time 