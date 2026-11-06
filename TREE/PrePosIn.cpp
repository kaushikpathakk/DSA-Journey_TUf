#include <iostream>
#include <vector>
#include <stack>

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
public:
    vector<vector<int>> allTraversals(Node* root) {
        vector<int> pre, in, post;
        if (root == nullptr) return {pre, in, post};

        stack<pair<Node*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) {
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->left != nullptr) {
                    st.push({it.first->left, 1});
                }
            } 
            else if (it.second == 2) {
                in.push_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->right != nullptr) {
                    st.push({it.first->right, 1});
                }
            } 
            else {
                post.push_back(it.first->data);
            }
        }

        return {pre, in, post};
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<vector<int>> result = sol.allTraversals(root);

    cout << "Preorder: ";
    for (int val : result[0]) cout << val << " ";
    cout << "\n";

    cout << "Inorder: ";
    for (int val : result[1]) cout << val << " ";
    cout << "\n";

    cout << "Postorder: ";
    for (int val : result[2]) cout << val << " ";
    cout << "\n";

    return 0;
}