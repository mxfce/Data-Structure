#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
/////////////////////////////////////////////////////////
class LinkedList
{

	class Node
	{
		private:
			int data;
			Node* next = NULL;
		public:
			void setData(int n) {data = n;}
			int getData() { return data; }
			void setNext(Node* n) { next = n; }
			Node* getNode() { return next; }

	};

	public:
		Node* head;
		LinkedList()
		{
			head = new Node;
		}
		void add(int val)
		{
			Node* itr = head;
			while(itr->getNode() != NULL)
				itr = itr->getNode();
			Node* n = new Node();
			n->setData(val);
			itr->setNext(n);
		}
		void printList()
		{
			Node* itr = head->getNode();
			while(itr != NULL)
			{
				printf("%d ",itr->getData());
				itr = itr->getNode();
			}
		}
		void insert(int pos,int val)
		{
			int cnt = 0;
			Node* itr = head->getNode();
			while(cnt != pos)
			{
				itr = itr->getNode();
				cnt++;
			}
			Node* n = new Node;
			n->setData(val);
			n->setNext(itr->getNode());
			itr->setNext(n);
		}
};
int main()
{
	LinkedList* list = new LinkedList;
	list->add(1);
	list->add(2);
	list->add(3);
	list->printList();
	printf("\n");
	list->insert(1,99);
	list->printList();
	//
}
