#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

/**
 * Traverses a binary tree in preorder and prints the value of each node.
 *
 * @param node a pointer to the root node of the binary tree
 *
 * @return void
 *
 * @throws None
 */
void preorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

/**
 * Performs a pre-order traversal of a binary tree iteratively.
 *
 * @param node A pointer to the root node of the tree.
 *
 * @throws None
 */
void preOrder_iter(Node *node)
{
    stack<Node *> s;
    s.push(node);

    while (!s.empty())
    {
        Node *n = s.top();
        s.pop();
        cout << n->data << " ";
        if (n->right != NULL)
        {
            s.push(n->right);
        }
        if (n->left != NULL)
        {
            s.push(n->left);
        }
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
Node *node = new Node(4);
node->left = new Node(3);
node->right = new Node(5);
node->left->right = new Node(6);
node->right->left = new Node(7);
node->left->left = new Node(8);
preorder(node);
cout << endl;
preOrder_iter(node);
return 0;
}