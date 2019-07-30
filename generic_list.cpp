#include <iostream>
#include <cassert>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node* next;
	Node<T>()	{}
	Node<T>(T data)	{this->data = data;	this->next = NULL;}
};


template <class T>
class List
{
	Node<T> *head=NULL, *tail=NULL;
	int _size;
	public:
		List()
		{
			_size = 0;
		}
		void add(T element)	{	push_back(element);	}
		void push_back(T element);
		void push_front(T element);
		void erase(Node<T> *ptr);
		void clear();
		int size()	{	return _size;	}
		Node<T>* getHead()		{	return head;	}
		Node<T>* getTail()		{	return tail;	}
};

template <class T>
void List<T>::push_front(T element)
{
	Node<T>* temp = new Node<T>(element);
	temp->next = head;
	head = temp;
	
	_size++;

	if(tail==NULL)
	{
		tail = temp;
	}
}

template <class T>
void List<T>::push_back(T element)
{
	Node<T>* temp = new Node<T>(element);
	
	_size++;

	if(tail!=NULL)
	{
		tail->next = temp;
	}
	
	tail = temp;
	
	if(head==NULL)
	{
		head = temp;
	}
}

template <class T>
void List<T>::clear()
{
	while(head!=NULL)
	{
		Node<T> *temp = head;
		head = head->next;
		delete(temp);
	}
	_size = 0;
}

template <class T>
void List<T>::erase(Node<T> *ptr)
{
	Node<T> *thead = head;
	if(thead == NULL)	return;

	if(thead == ptr && tail == ptr)	
	{
		head = NULL;
		tail = NULL;
		delete(ptr);
		ptr = NULL;
		_size--;
		return;
	}
	else if(thead == ptr)
	{
		head = head->next;
		delete(ptr);
		ptr = head;
		_size--;
		return;
	}

	while(thead!=NULL && thead->next!=ptr)	thead = thead->next;
	if(thead==NULL)	{cerr<<"invalid pointer\n"; exit(0);}

	thead->next = ptr->next;
	
	if(tail == ptr)
	{
		tail = thead;
	}

	delete(ptr);
	ptr = thead->next;
	_size--;
}

template <class T>
void traverse(Node<T>* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}


int main()
{
	List<int> g;
	
	for(int i=1;i<=10;i++)
	{
		g.add(i);
		traverse(g.getHead());
	}

	while(g.getHead()!=NULL)
	{
		g.erase(g.getHead());
		traverse(g.getHead());
	}
	cout<<endl;
	return 0;
}