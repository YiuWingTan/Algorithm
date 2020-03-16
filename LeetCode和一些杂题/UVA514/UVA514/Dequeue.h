//#pragma once

template<class T>
struct Node
{
	Node(T);
	Node();
	~Node();

	T value;

	Node<T>* next;

	Node<T>*pre;
};

template<class T>
class Dequeue
{
private :
	int size;

	Node<T>* head;

	Node<T>*tail;

public:

	Dequeue();

	~Dequeue();

	//在队列头部进行压入
	int Push_Front(T);
	//在队列尾部进行压入
	int Push_Back(T);

	T Pop_Front();

	T Pop_Back();

	int Size();

	bool isEmpty();

};

template<class T>
Node<T>::Node()
{
	next = nullptr;

	tail = nullptr;
};
template<class T>
Node<T>::Node(T t)
{
	next = nullptr;

	pre = nullptr;

	value = t;
};
template<class T>
Node<T>::~Node()
{
	next = nullptr;

	pre = nullptr;
};


template<class T>
Dequeue<T>::Dequeue()
{
	head = nullptr;

	tail = nullptr;

	size = 0;
};
template<class T>
int Dequeue<T>::Push_Front(T t)
{
	Node<T>* node = new Node<T>(t);

	node->next = head;

	if (head != nullptr)
	{
		head->pre = node;
	}
	else {
		 head = node;
		 tail = head;
	}

	head = node;

	size++;

	return 1;
};

template<class T>
int Dequeue<T>::Push_Back(T t)
{
	Node<T>* node = new Node<T>(t);

	node->pre = tail;
	if (tail != nullptr)
	{
		tail->next = node;
	}
	else
	{
		tail = node;
		head = tail;
	}

	tail = node;

	size++;

	return 1;
};

template<class T>
T Dequeue<T>::Pop_Front()
{
	//if (size <= 0) return void;

	T t = head->value;

	Node<T>* n = head->next;

	if (n != nullptr)
		n->pre = nullptr;
	head->next = nullptr;
	head->pre = nullptr;

	
	delete(head);

	head = n;

	if (head == nullptr)
	{
		head = tail = nullptr;
	}

	size--;

	if (size <= 0)
	{
		head = nullptr;
	}

	return t;
};

template<class T>
T Dequeue<T>::Pop_Back()
{
	//if (size <= 0) return; void;

	T t = tail->value;

	Node<T> * node = tail->pre;

	tail->next = nullptr;

	tail->pre = nullptr;

	if (node != nullptr)
		node->next = nullptr;

	delete(tail);


	tail = node;

	if (tail == nullptr)
	{
		head = tail = nullptr;
	}

	size--;

	return t;
};

template<class T>
int Dequeue<T>::Size()
{
	return size;
};


template<class T>
bool Dequeue<T>::isEmpty()
{
	if (size <= 0) return true;
	return false;
};

template<class T>
Dequeue<T>::~Dequeue()
{

};
