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
void postOrder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

void postOrder_iter(Node *node)
{
    // use two stack left then right in stack 1 once popped from stack 1 put in stack 2
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(node);
    // Node *n = s1.top();
    while (!s1.empty())
    {
        node = s1.top();
        s1.pop();
        int val = node->data;
        s2.push(node);
        if (node->left != NULL)
        {
            s1.push(node->left);
        }
        if (node->right != NULL)
        {
            s1.push(node->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
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

postOrder(node);
cout << endl;
postOrder_iter(node);

return 0;
}