#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
using namespace std;
struct Node
{
    Node* left;
    Node* right;
    int key;
    int height;
    char des[100];
};
Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}
int height(Node* node)
{
    if(node == NULL)
        return -1;
    return node->height;
}
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;

    return y;
}
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}
Node* insert(Node* node,int key)
{
    if(node == NULL)
        return newNode(key);

    if(key < node->key)
        node->left = insert(node->left,key);

    if(key > node->key)
        node->right = insert(node->right,key);

    node->height = max(height(node->left),height(node->right)) + 1;
    int balance = height(node->left) - height(node->right);

    if(balance > 1 && key < node->key)
        return rightRotate(node);
    if(balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && key > node->key)
        return leftRotate(node);
    if(balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorder(Node* node)
{
    if(node == NULL)
        return ;
    inorder(node->left);
    printf("%d ",node->key);
    inorder(node->right);
}
int main()
{
    Node* root = NULL;
    int arr[] = {3,2,1};
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0; i < n; ++i)
        root = insert(root,arr[i]);
    inorder(root);
}
//g++ -std=c++11 main.cpp -o main && timeout 2s ./main < inputf.in > outputf.out
