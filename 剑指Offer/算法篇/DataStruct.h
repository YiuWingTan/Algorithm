#pragma once

#pragma once
#include<iostream>
#include<vector>
using namespace std;





///////////////////////////////////////////////////////����
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
	cout << endl;
}

////////////////////////////////////////////////////////

////////////////////////////////////////////////////////��
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

//ɾ��һ����
template<class T>
inline BinaryTreeNode<T>* deleteTree(BinaryTreeNode<T>*&node)
{
	if (node == NULL) return NULL;
	node->left = deleteTree(node->left);
	node->right = deleteTree(node->right);
	delete node;
	return NULL;
}

//���һ����
template<class T>
inline void ShowTree(BinaryTreeNode<T>*&node)
{
	if (node == NULL) return;
	printf("�ڵ� ");
	cout << node->val << "  ";
	if (node->left != NULL)
	{
		printf("  ���ӽڵ�  ");
		cout << node->left->val;
	}
	if (node->right != NULL)
	{
		printf("  ���ӽڵ�  ");
		cout << node->right->val;
	}
	cout << endl;
	ShowTree(node->left);
	ShowTree(node->right);
}
