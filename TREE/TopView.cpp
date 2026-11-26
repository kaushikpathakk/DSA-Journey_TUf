#include <iostream>
#include <vector>
#include <map>
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
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* star = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end()) {
                mpp[line] = star->data;
            }
            if (star->left) {
                q.push({star->left, line - 1});
            }
            if (star->right) {
                q.push({star->right, line + 1});
            }
        }

        for (auto k : mpp) {
            ans.push_back(k.second);
        }

        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> res = sol.topView(root);

    for (int val : res) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}