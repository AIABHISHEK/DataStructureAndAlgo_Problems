#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void preorder(Node *node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<endl;
    preorder(node->left);
    preorder(node->right);
}


void inorder(Node *node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<endl;
    inorder(node->right);
}

void postOrder(Node *node){
    if(node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<endl;
}

void levelOrder(Node *node){
    queue<Node *> q;
    q.push(node);

    while (!q.empty()){
        Node *n = q.front();
        q.pop();
        if(n != NULL){
            cout<<n->data<<endl;
            q.push(n->left);
            q.push(n->right);
        }
    }
}

void preOrder_iter(Node *node){
    stack<Node *> s;
    s.push(node);
    
    while (!s.empty())
    {
        Node *n = s.top();
        s.pop();
        cout << "h";
        cout << n->data << endl;
        if(n ->right != NULL){
            s.push(n->right);
        }
        if(n->left != NULL){
            s.push(n->left);
        }
    }
    
}

/**
 * Performs an in-order traversal of a binary tree iteratively.
 *
 * @param node The root node of the binary tree.
 *
 * @throws None.
 */
void inOrder_iter(Node* node){

    stack<Node *> s;
    Node *n = node;
    while (true){
        //traverse left until we reach leaf node 
        if(n != NULL){
            s.push(n);
            n = n->left;
        }
        else{
            if(s.empty() == true)
                break;
            n = s.top();
            s.pop();
            cout << n -> data << endl;
            n = n->right;
        }
    }
}

void postOrder_iter(Node *node){
    //use two stack left then right in stack 1 once popped from stack 1 put in stack 2
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(node);
    // Node *n = s1.top();
    while (!s1.empty()){
        node = s1.top();
        s1.pop();
        int val = node->data;
        s2.push(node);
        if(node->left != NULL){
            s1.push(node->left);
        }
        if (node->right != NULL)
        {
            s1.push(node->right);
        } 
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << endl;
        s2.pop();
    }
    
}
class Tree{

};

int main(){

ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
Node *node = new Node(4);
node->left = new Node(3);
node->right = new Node(5);
node->left->right = new Node(6);
node->right->left = new Node(7);
node->left->left = new Node(8);
// preorder(node);
// inorder(node);
postOrder(node);
// levelOrder(node);
// preOrder_iter(node);
// inOrder_iter(node);
postOrder_iter(node);
return 0;
}