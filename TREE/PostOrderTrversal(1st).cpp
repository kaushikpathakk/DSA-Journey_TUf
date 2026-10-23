#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // reverse() ke liye

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
        vector<int> ans;
        if (root == nullptr) return ans;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();
            ans.push_back(curr->data);

        
            if (curr->left != nullptr) {
                st.push(curr->left);
            }
            if (curr->right != nullptr) {
                st.push(curr->right);
            }
        }

     
        reverse(ans.begin(), ans.end());

        return ans;
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
// this method is brought by little bit change in the 2 stack one , rather than using st2 we used a array a pushed nodes teh same way an at the end of iteration we just reversed it (strivere's video method is complicated )