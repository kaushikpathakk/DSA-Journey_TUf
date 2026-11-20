#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<Node*> qnodes;
        qnodes.push(root);
        bool flag = true;

        while (!qnodes.empty()) {
            int size = qnodes.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                Node* node = qnodes.front();
                qnodes.pop();

                int index = (flag) ? i : (size - 1 - i);
                row[index] = node->data;

                if (node->left) qnodes.push(node->left);
                if (node->right) qnodes.push(node->right);
            }

            flag = !flag;
            for (int val : row) {
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
    vector<int> ans = sol.zigZagTraversal(root);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}