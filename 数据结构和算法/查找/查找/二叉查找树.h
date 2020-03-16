#pragma once
class BinaryTree
{
private:

	typedef struct Node
	{
		int value;
		int key;
		int count;
		Node* left;
		Node* Right;

		Node(int _key,int _value,int _count)
		{
			key = _key;

			value = _value;

			count = _count;

			left = nullptr;

			Right = nullptr;
		}
	};

	Node* root;

	Node* put(Node* x,int key, int value);
	
	void preOrder(Node * x);
	Node* get(Node* x ,int key);
	Node* deleted(Node* x,int key);
	bool contain(Node* x, int key);

public:
	BinaryTree()
	{
		root = nullptr;
	}

	~BinaryTree() {

	}
	void Put(int key, int value);
	void PreOrder();
	int Get(int key);

	void Deleted(int key);

	bool Contain(int key);

};