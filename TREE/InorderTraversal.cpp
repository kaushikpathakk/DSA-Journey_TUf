#include <iostream>
#include <vector>

using namespace std;

struct Node {
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
    void traverse(Node* root, vector<int>& ans) {
        if (root == nullptr) return;

        traverse(root->left, ans);
        ans.push_back(root->data);
        traverse(root->right, ans);
    }

public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solver;
    vector<int> res = solver.inOrder(root);

    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}