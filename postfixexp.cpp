#include <iostream>
#include <stack>
using namespace std;

// Node structure for the expression tree
struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to construct the expression tree
Node* constructExpressionTree(string expression) {
    stack<Node*> st;
    for (int i = expression.length() - 1; i >= 0; i--) {
        char c = expression[i];
        Node* newNode = new Node(c);
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            newNode->left = st.top();
            st.pop();
            newNode->right = st.top();
            st.pop();
        }
        st.push(newNode);
    }
    return st.top();
}

// Function for post-order traversal of the expression tree
void postOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << " ";
}

// Function to delete the expression tree
void deleteExpressionTree(Node* root) {
    if (root == nullptr)
        return;

    deleteExpressionTree(root->left);
    deleteExpressionTree(root->right);
    delete root;
}

int main() {
    string expression = "+--a*bc/def";

    // Construct the expression tree
    Node* root = constructExpressionTree(expression);

    // Perform post-order traversal
    cout << "Expression Tree Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Delete the expression tree
    deleteExpressionTree(root);

    return 0;
}
