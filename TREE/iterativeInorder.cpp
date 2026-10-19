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
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> in;
        if (root == nullptr) return in;

        stack<Node*> st;
        Node* node = root;

        while (true) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty()) break;
                node = st.top();
                st.pop();
                in.push_back(node->data);
                node = node->right;
            }
        }
        return in;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.inOrder(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}