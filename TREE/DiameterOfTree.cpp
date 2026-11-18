// Longest path between two nodes of a tree
// Brute force: find height of every node and maximize (lh + rh) -> O(N^2)
// Optimal: calculate diameter while computing height in a single DFS -> O(N)

#include <iostream>
#include <algorithm>

using namespace std;

class Node {
  public: // <-- Yeh zaroori hai
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
    int DiameterOfBt(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

  private:
    int height(Node* root, int &diameter) {
        if (root == nullptr) return 0;

        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};

int main() {
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Diameter of Binary Tree: " << sol.DiameterOfBt(root) << "\n";

    return 0;
}