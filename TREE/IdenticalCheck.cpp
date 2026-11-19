#include <iostream>

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
    bool isIdentical(Node* p, Node* q) {
        if (p == nullptr || q == nullptr) {
            return (p == q);
        }
        return (p->data == q->data) &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }
};

int main() {
    
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);

    
    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);

    Node* r = new Node(1);
    r->left = new Node(2);

    Solution sol;

    cout << "p and q identical: " << (sol.isIdentical(p, q) ? "Yes" : "No") << "\n"; // Output: Yes
    cout << "p and r identical: " << (sol.isIdentical(p, r) ? "Yes" : "No") << "\n"; // Output: No

    return 0;
}