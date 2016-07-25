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
using namespace std;
class Node
{
	public: 
		Node* nextNode;
		int val;
		Node(Node* node)
		{
			nextNode = node;
		}
		Node(Node* node, int n)
		{
			nextNode = node;
			val = n;
		}
};
class LinkedList
{
	private:
		Node* root = new Node(NULL,-1);
		Node* leaf;
	public:
		void add(int n)
		{
			Node* newNode = new Node(NULL,n);
			Node* itr = root;
			while(itr->nextNode != NULL)
			{
				itr = itr->nextNode;
			}
			itr->nextNode = newNode;
		}
		void insert(int pos, int n)
		{
			Node* newNode = new Node(NULL,n);
			Node* prev = root;
			Node* curr = root->nextNode;
			int i = 0;
			while(curr != NULL)
			{
				if(i == pos)
				{
					prev->nextNode = newNode;
					newNode->nextNode = curr;
					return ;
				}
				i++;
				prev = curr;
				curr = curr->nextNode;
				
			}
			printf("WARNING! :: Can't Insert, variable pos %d is out of bound\n",pos);
		}
		void remove(int val)
		{
			Node* curr = root->nextNode;
			Node* prev = root;
			while(curr->val != val)
			{
				if(curr->nextNode == NULL)
					return ;
				prev = curr;
				curr = curr->nextNode;
			}
			prev->nextNode = curr->nextNode;
		}
		bool find(int val)
		{
			Node* itr = root->nextNode;
			while(itr != NULL)
			{
				if(itr->val == val)
					return true;
				itr = itr->nextNode;
			}
			return false;
		}
		void printAllElements()
		{
			Node* itr = root->nextNode;
			while(itr != NULL)
			{
				printf("%d ",itr->val);
				itr = itr->nextNode;
			}
			printf("\n");
		}
};

int main()
{
	LinkedList* list = new LinkedList;
	list->add(2);
	list->add(1);
	list->add(3);
	list->remove(2);
	list->remove(3);
	printf("%d",list->find(3));
	list->printAllElements();
	
}
