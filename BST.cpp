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

class Node
{
	public:
		Node* left;
		Node* right;
		int data;
	public:
		Node(int val)
		{
			data = val;
		}
};
class BST
{
	private:
		Node* root;
	public:
		void insert(int val)
		{
			Node* newNode = new Node(val);
			Node* itr = root;
			if(root == NULL)
				root = newNode;
			else
			{
				while(true)
				{
					if(val > itr->data)
					{
						if(itr->right == NULL)
						{
							itr->right = newNode;
							return ;
						}
						itr = itr->right;

					}
					else if(val < itr->data)
					{
						if(itr->left == NULL)
						{
							itr->left = newNode;
							return ;
						}
						itr = itr->left;
					}
				}
			}
		}
		Node* getRoot()
		{
			return root;
		}
		void findMax()
		{
			Node* itr = root;
			while(itr->right != NULL)
				itr = itr->right;
			cout << itr->data << endl;
		}
		void findMin()
		{
			Node* itr = root;
			while(itr->left != NULL)
				itr = itr->left;
			cout << itr->data << endl;
		}
		void inorder(Node* itr)
		{
			if(itr == NULL)
				return;
			if(itr->left != NULL)
				inorder(itr->left);
			cout << itr->data << endl;
			if(itr->right != NULL)
				inorder(itr->right);
		}
};
int main()
{
	BST* bst = new BST();
	bst->insert(15);
	bst->insert(4);
	bst->insert(9);
	bst->insert(55);
	bst->insert(22);
	cout << "test" << endl;
	bst->findMax();
	bst->findMin();
}
