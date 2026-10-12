#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node {
int data ;
Node* left ;
Node* right ;
Node( int val){
  data = val;
  left = nullptr;
  right = nullptr;
}
};
class Solution {
  public :
  vector<int> preorderTrversal (Node* root ){
  vector<int>preorder;
  if(root == NULL ) return preorder;

  stack<Node*> st;
  st.push(root);

  while(!st.empty()){
    root = st.top();
    st.pop();
    preorder.push_back(root->data);
    if(root->right != NULL){
      st.push(root->right);
    }
    if(root->left != NULL){
      st.push(root->left);
    }
  }
  return preorder;

  }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.preorderTrversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}