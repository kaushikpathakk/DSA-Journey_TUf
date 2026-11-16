#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    bool isBalanced(Node* root) {
        return dfsHeight(root) != -1;
    }

  private:
    int dfsHeight(Node* root) {
        if (root == nullptr) return 0;

        int lh = dfsHeight(root->left);
        if (lh == -1) return -1;

        int rh = dfsHeight(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }
};

int main() {
    
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    Solution sol;

    cout << "Tree 1 Balanced: " << (sol.isBalanced(root1) ? "Yes" : "No") << "\n";
    cout << "Tree 2 Balanced: " << (sol.isBalanced(root2) ? "Yes" : "No") << "\n";

    return 0;
}