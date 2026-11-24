#include<vector>
#include<iostream>
#include<map>
#include<queue>
using namespace std;
class Node{
  public:
  int data ;
  Node* left;
  Node* right;
  Node(int val){
    data = val;
    left = nullptr;
    right = nullptr;
  }
};
class Solution {
  public :
  vector<vector<int>>VerticalTrversal( Node* root){
    vector<vector<int>>ans;
    if(root == nullptr) return ans ;
    map<int, map<int, vector<int>>>nodes;
    queue<pair<Node*, pair<int, int>>>todo;
    todo.push({root, {0,0}});
    while(!todo.empty()){
      auto p = todo.front();
      todo.pop();

      Node* node = p.first;
      int x = p.second.first;
      int y = p.second.second;

      nodes[x][y].push_back(node->data);
      if(node->left){
       todo.push({node->left, {x-1, y+1}});
      }
       if(node->right){
       todo.push({node->right, {x+1, y+1}});
      }
    }
      for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
  }
};
int main(){
  return 0 ;
}