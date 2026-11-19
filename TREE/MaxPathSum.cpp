#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    int findMaxSum(Node* root) {
        int maxi = INT_MIN;
        maxPathsum(root, maxi);
        return maxi;
    }

  private:
    int maxPathsum(Node* root, int &maxi) {
        if (root == nullptr) return 0;

        int lPath = max(0, maxPathsum(root->left, maxi));
        int rPath = max(0, maxPathsum(root->right, maxi));

        maxi = max(maxi, lPath + rPath + root->data);

        return root->data + max(lPath, rPath);
    }
};

int main() {
    // Tree structure:
    //       10
    //      /  \
    //    -2    5
    //    /
    //   20
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(5);
    root->left->left = new Node(20);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.findMaxSum(root) << "\n"; // Output: 33

    return 0;
}