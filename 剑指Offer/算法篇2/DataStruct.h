#pragma once
#include<iostream>
#include<vector>
using namespace std;


///////////////////////////////////////////////////////链表
template<class T>
struct SingleListNode
{
	T val;
	SingleListNode<T> *next;
	SingleListNode(T _val)
	{
		val = _val;
		next = NULL;
	}
};

//双向链表
template<class T>
struct DoubleListNode
{
	T val;
	DoubleListNode<T> *prev;
	DoubleListNode<T> *next;
	DoubleListNode(T _val) :prev(nullptr), next(nullptr)
	{
		val = _val;
	}

};

template<class T>
inline void CreateDoubleList(vector<T> &arr,DoubleListNode<T> *p)
{
	for (int i = 0; i < arr.size(); i++)
	{
		DoubleListNode<T> *node = new DoubleListNode<T>(arr[i]);
		if (p == NULL)
		{
			p = node;
		}
		else
		{
			DoubleListNode<T> *q = p;
			while (q->next != NULL) q = q->next;
			q->next = node;
		}
	}
}

template<class T>
inline void CreateSingleList(vector<T> &arr, SingleListNode<T> *&p)
{
	for (int i = 0; i < arr.size(); i++)
	{
		SingleListNode<T> *node = new SingleListNode<T>(arr[i]);
		if (p == NULL)
		{
			p = node;
		}
		else
		{
			SingleListNode<T> *q = p;
			while (q->next != NULL) q = q->next;
			q->next = node;
		}
	}
};

template<class T>
inline void DeleteSingleList(SingleListNode<T> *&p)
{
	SingleListNode<T>* node = p;
	while (node != NULL)
	{
		auto pn = node->next;
		delete node;
		node = pn;
	}

	p = NULL;
}

template<class T>
inline void ShowList(SingleListNode<T> *&p)
{
	SingleListNode<T>*node = p;

	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
}

////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
template<class T>
struct BinaryTreeNode
{
	T val;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
	BinaryTreeNode<T> *par;

	BinaryTreeNode(T _val)
	{
		val = _val;
		left = nullptr;
		right = nullptr;
	}
};

//删除一棵树
template<class T>
inline BinaryTreeNode<T>* deleteTree(BinaryTreeNode<T>*&node)
{
	if (node == NULL) return NULL;
	node->left = deleteTree(node->left);
	node->right = deleteTree(node->right);
	delete node;
	return NULL;
}

//输出一棵树
template<class T>
inline void ShowTree(BinaryTreeNode<T>*&node)
{
	if (node == NULL) return;
	printf("节点 ");
	cout << node->val << "  ";
	if (node->left != NULL)
	{
		printf("  左子节点  ");
		cout << node->left->val;
	}
	if (node->right != NULL)
	{
		printf("  右子节点  ");
		cout << node->right->val;
	}
	cout << endl;
	ShowTree(node->left);
	ShowTree(node->right);
}

vector<int> preOrder;//前序
vector<int> midOrder;//中序

BinaryTreeNode<int>* createTree(int par, int left, int right, int index)
{
	BinaryTreeNode<int> *node = new BinaryTreeNode<int>(midOrder[par]);


	//判断有没有左子树
	if (par != left)
	{
		//有
		int leftIndex = index + 1;
		int i = par-1;
		for (; i >=left&&midOrder[i] != preOrder[leftIndex]; i--);
		if (i == left-1)
			throw exception("非法输入");
		node->left = createTree(i, left, par - 1, leftIndex);
	}
	//判断有没有右子树
	if (par != right)
	{
		int rightIndex;
		if (par != left)
			rightIndex = index + (par - left + 1);
		else rightIndex = index + 1;
		int i = right;
		for (; i >par&&preOrder[rightIndex] != midOrder[i]; i--);
		if (i==par)
			throw exception("非法输入");
		node->right = createTree(i, par + 1, right, rightIndex);
	}
	return node;
}
BinaryTreeNode<int>* CreateTreeByPreOrderAndMidOrder(vector<int>&prev,vector<int> &mid,int parInMid)
{
	BinaryTreeNode<int>* root;
	preOrder = prev;
	midOrder = mid;
	if (preOrder.size() != midOrder.size()) return nullptr;
	root = createTree(parInMid, 0, midOrder.size() - 1, 0);
	return root;
}





