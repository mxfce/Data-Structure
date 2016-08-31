
public class LinkedList 
{
	private Node head = new Node(null,-1);
	int size = 0;
	public void add(int _key)
	{
		Node newNode = new Node(null,_key);
		newNode.next = head.next;
		head.next = newNode;
		size++;
	}
	public void insert(int index,int _key)
	{
		int i = 0;
		Node itr = head;
		Node newNode = new Node(null,_key);
		if(index >= size)
		{
			System.out.println("index out of bound.");
			return ;
		}
		while(itr.next!= null)
		{
			if(i++ == index)
			{
				newNode.next = itr.next;
				itr.next = newNode;
				size++;
				return ;
			}
			itr = itr.next;
		}
	}
	public Node find(int _key)
	{
		Node itr = head.next;
		while(itr != null)
		{
			if(itr.key == _key)
				return itr;
			itr = itr.next;
		}
		return null;
	}
	public void remove(int _key)
	{
		Node prev = head;
		Node curr = head.next;
		while(curr != null)
		{
			if(curr.key == _key)
			{
				prev.next = curr.next;
				size--;
				return ;
			}
			prev = curr;
			curr = curr.next;
		}
	}
	public boolean isEmpy()
	{
		if(size == 0)
			return true;
		return false;
	}
	public void printAll()
	{
		Node itr = head.next;
		while(itr != null)
		{
			System.out.print(itr.key+" ");
			itr = itr.next;
		}
		System.out.println();
	}
	class Node
	{
		Node next;
		int key;
		Node(Node _next,int _key)
		{
			key = _key;
			next = _next;
		}
	}
}

