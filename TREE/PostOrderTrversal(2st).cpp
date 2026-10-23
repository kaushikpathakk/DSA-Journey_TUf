#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> postOrder(Node* root) {
        vector<int> PO;
        if (root == nullptr) return PO;

        stack<Node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);

            if (root->left != nullptr) {
                st1.push(root->left);
            }
            if (root->right != nullptr) {
                st1.push(root->right);
            }
        }

        while (!st2.empty()) {
            PO.push_back(st2.top()->data);
            st2.pop();
        }

        return PO;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.postOrder(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}