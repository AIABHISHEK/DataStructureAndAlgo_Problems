#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};



int balancedTree(Node *root){
    if(!root)
        return 0;
    int lh = balancedTree(root->left);
    if(lh == -1)
        return -1;
        int rh = balancedTree(root->right);
    if(rh == -1)
        return -1;
    if(abs(lh-rh) > 1){
        return -1;
    }
    return max(lh, rh) + 1;
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
node->left->left->left = new Node(90);
node->left->left->right = new Node(70);
// node->left->left->right->left = new Node(34);

cout << balancedTree(node);

return 0;
}