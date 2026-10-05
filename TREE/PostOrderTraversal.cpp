#include<iostream>
#include<vector>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;
  node(int val){
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

class Solution{
  void traversal ( node* root , vector<int>&ans){
    if(root == nullptr) return;
    traversal(root->left , ans);
    traversal(root->right , ans);
    ans.push_back(root->data);
  }
  public :
  vector<int> PostOrder(node* root){
    vector<int>ans;
    traversal(root, ans);
    return ans;
  }
};

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    Solution solver;
    vector<int> res = solver.PostOrder(root);

    for(int val : res){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}