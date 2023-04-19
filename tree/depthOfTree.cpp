
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

int depthOfTree(Node *root){

    queue<Node *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()){
        depth++;
        int sizeOfQ = q.size();

        for (int i = 0; i < sizeOfQ; i++){
            Node *node = q.front();
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
    }
    return depth;
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
node->left->left->right->left = new Node(34);
/*
                        4
                    3   ,    5
                8     6 , 7
            90    70
                34



*/
cout<<depthOfTree(node);
return 0;
}