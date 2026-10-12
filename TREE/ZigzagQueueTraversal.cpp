#include<iostream>
#include<vector>
#include<queue>
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
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel(size);

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                int index = leftToRight ? i : (size - 1 - i);
                currentLevel[index] = curr->data;

                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            leftToRight = !leftToRight;

            for (int val : currentLevel) {
                result.push_back(val);
            }
        }

        return result;
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.zigZagTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}