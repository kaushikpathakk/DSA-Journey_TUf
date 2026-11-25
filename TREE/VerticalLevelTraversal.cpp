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
  
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<vector<int>> res = sol.VerticalTrversal(root);

    for (const auto& col : res) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
 
