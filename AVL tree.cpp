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
#include <chrono>
using namespace std;
struct Node
{
    Node* left;
    Node* right;
    int data;
    int height;
    int size;
};
Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    node->height = 0;
    node->size = 1;
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
    //rotation
    y->left = x;
    x->right = T;
    //update height
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    //return
    return y;
}
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T = x->right;
    //rotation
    x->right = y;
    y->left = T;
    //update height
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    //return
    return x;
}
Node* insert(Node* node,int key)
{
    if(node == NULL)
        return newNode(key);
    if(key < node->data)
    {
        node->left = insert(node->left,key);
    }
    else
    {
        node->right = insert(node->right,key);
    }
    node->height = max(height(node->left),height(node->right)) + 1;
    int balance = height(node->left) - height(node->right);
    if(balance < -1 && key > node->right->data)
    {
        return leftRotate(node);
    }
    else if(balance > 1 && key < node->left->data)
    {
        return rightRotate(node);
    }
    else if(balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    else if(balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    return node;
}
void inorder(Node* itr)
{
	if(itr == NULL)
		return;
	inorder(itr->left);
	printf("%d ",itr->data);
	inorder(itr->right);
}
int main()
{
    Node* root = NULL;
    root = insert(root,10);
    root = insert(root,3);
    root = insert(root,5);
    cout << root-> data << endl;
    cout << root->left ->data<< endl;
    cout << root->right->data << endl;
}
//g++ -std=c++11 main.cpp -o main && timeout 2s ./main < inputf.in > outputf.out
