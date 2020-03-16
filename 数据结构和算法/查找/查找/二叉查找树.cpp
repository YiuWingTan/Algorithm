#include"¶ş²æ²éÕÒÊ÷.h"
#include<iostream>
bool BinaryTree::Contain(int key)
{
	return contain(root, key);
}

bool BinaryTree::contain(Node* x, int key)
{
	if (x == nullptr) return false;

	if (key == x->value) return true;
	else
		if (key > x->value) return contain(x->Right, key);
		else if (key < x->value) return contain(x->left, key);
}

void BinaryTree::Deleted(int key)
{
	root = deleted(root,key);
}

BinaryTree::Node* BinaryTree::deleted(Node* x, int key)
{
	static int offset = 1;
	if (x == nullptr)
	{
		return nullptr;

		offset = 0;
	}

	if (x->key == key) { Node* ptr = x->left; delete(x); return ptr; }
	else if (x->key > key) x->left =  deleted(x->left, key);
	else x->Right = deleted(x->Right, key);
	x->count -= offset;
	return x;
}

int BinaryTree::Get(int key)
{
	Node* x = get(root,key);
	if (x != nullptr)
	{
		return x->value;
	}
	return -1;
}


BinaryTree::Node* BinaryTree::get(Node* x, int key)
{
	if (x == nullptr) return nullptr;
	else if (x->key == key) return x;
	else if (x->key > key) return get(x->left, key);
	else return get(x->Right,key);
}

void BinaryTree::Put(int key, int value)
{
	root = put(root,key,value);
}

BinaryTree::Node* BinaryTree::put(Node* x,int key,int value)
{
	static int offset = 1;

	if (x == nullptr) { Node* n = new Node(key, value, 1); return n; }
	else if (x->key == key) { return x; offset = 0; }
	else if (x->key > key) x->left = put(x->left,key,value);
	else x->Right = put(x->Right,key,value);

	x->count += offset;

	return x;
}

void BinaryTree::PreOrder()
{
	preOrder(root);
}

void BinaryTree::preOrder(Node* x)
{
	if (x == nullptr) return;

	preOrder(x->left);
	std::cout << x->key << " ";
	preOrder(x->Right);
}

