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
 * Traverses a binary tree in inorder.
 *
 * @param node a pointer to the root of the binary tree
 *
 * @return void
 *
 * @throws None
 */
void inorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

/**
 * Traverses a binary tree in in-order traversal iteratively.
 *
 * @param node a pointer to the root node of the binary tree
 *
 * @throws None
 */
void inOrder_iter(Node *node)
{

    stack<Node *> s;
    Node *n = node;
    while (true)
    {
        // traverse left until we reach leaf node
        if (n != NULL)
        {
            s.push(n);
            n = n->left;
        }
        else
        {
            if (s.empty() == true)
                break;
            n = s.top();
            s.pop();
            cout << n->data << " ";
            n = n->right;
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

inorder(node);
cout << endl;
inOrder_iter(node);
return 0;
}