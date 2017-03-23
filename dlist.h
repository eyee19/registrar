//Everett Yee
//Header file for generic doubly linked list

#ifndef DLIST_H
#define DLIST_H

//class for creating nodes for the linked list
template <typename T>
class ListNode
{
	public:
		//ListNode();			//default constructor
		ListNode(T d);			//constructor
		virtual ~ListNode();	//destructor
		T data;					//data for node
		ListNode<T> *next;		//nodes next pointer
		ListNode<T> *prev;		//nodes previous pointer
};

//default constructor
//template <typename T>
//ListNode<T>:: ListNode()
//{
//}

//constructor for the list node class, sets data and sets next and previous ponters to zero
template <typename T>
ListNode<T>:: ListNode(T d)
{
	data = d;
	next = 0;
	prev = 0;
}

//destructor for list node
template <typename T>
ListNode<T>:: ~ListNode()
{
	//data = NULL;
	delete next;
	delete prev;
}

//class for the doubly linked list
template <typename T>
class DList 
{
	public:
		DList();							//constructor
		virtual ~DList();					//destructor
		void addBack(T d);					//adds node to the back of the list
		void removeFront();					//removes node from front of the list
		T getFront();						//gets item at the front of the list
		bool isEmpty(){return (size == 0);}	//checks if list is empty
		int getSize(){return size;}			//returns size of list
		//void printList();
		
	private:
		ListNode<T>* front;
		ListNode<T>* back;
		int size;
};

//constructor, sets size, listnode front and back pointers to 0	
template <typename T>
DList<T>:: DList()
{
	size = 0;
	front = 0;
	back = 0;
}

//destructor for link list, uses removeFront until list is empty
template <typename T>
DList<T>:: ~DList()
{
	while (!isEmpty())
	{
		removeFront();
	}
}

//add nodes to the back of the list
template <typename T>
void DList<T>:: addBack(T d)
{
	ListNode<T>* newNode = new ListNode<T>(d);
	
	//if list is empty
	if (isEmpty())
	{
		front = newNode;
		back = newNode;
		++size;
	}
	//is list is not empty 
	else
	{
		back -> next = newNode;
		newNode -> prev = back;
		back = newNode;
		++size;
	}
}

//removes node from the front of the list
template <typename T>
void DList<T>:: removeFront()
{
	ListNode<T>* deleteNode = front;
	
	//if there is one node left in the list
	if (getSize() == 1)
	{
		front = deleteNode -> next;
		back = NULL;
		//delete deleteNode;
		--size;
	}
	//more than one nodes in the list
	else
	{
		front = deleteNode -> next;
		front -> prev = NULL;
		//delete deleteNode;
		--size;
	}
}

//returns the item in the front of the list
template <typename T>
T DList<T>:: getFront()
{
	ListNode<T>* frontNode = front;
	return frontNode -> data;	
}

//prints the list, used for debugging purposes
/*template<typename T>
void DList<T>:: printList()
{
	if (isEmpty())
	{
		std::cout << "Empty" << std::endl;
	}
	else
	{
		ListNode<T>* printNode = front;
		while (printNode -> next != NULL)
		{
			std::cout << printNode -> data << " ";
			printNode = printNode -> next;
		}
		std::cout << printNode ->data << " ";
		std::cout << std::endl;
	}
}*/

#endif // DLIST_H