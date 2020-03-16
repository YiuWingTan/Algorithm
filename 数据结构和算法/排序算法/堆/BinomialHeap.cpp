#include"BinomialHeap.h"
#include<queue>
#include<iostream>
using namespace std;
template<class T>
BinomialHeap<T>::BinomialHeap(Compare func) :num(0), root(nullptr), comFunc(func)
{

}

template<class T>
BinomialHeap<T>::BinomialHeap(const BinomialHeap<T>& heap)
{
	if (heap.root == root) return;
	clear(root);
	num = heap.num;
	root = copy(heap.root);
}

template<class T>
BinomialHeap<T>& BinomialHeap<T>::operator=(const BinomialHeap<T>& heap)
{
	// TODO: 在此处插入 return 语句
	if (heap.root == root) return *this;
	clear(root);
	num = heap.num;
	root = copy(heap.root);
}

template<class T>
BinomialHeap<T>::~BinomialHeap()
{
	if (root != nullptr)
	{
		clear(root);
		root = nullptr;
	}
}

template<class T>
void BinomialHeap<T>::clear()
{
	if (root != nullptr)
	{
		clear(root);
		root = nullptr;

	}
	num = 0;
}
template<class T>
bool BinomialHeap<T>::pop()
{
	if (empty()) return false;
	if (num==1)
	{
		delete root;
		num--;
		root = nullptr;
		return true;
	}
	BinomialNode<T> *pre = nullptr;
	BinomialNode<T> *min = root;
	BinomialNode<T> *node = root;
	while (node->bor != nullptr)
	{
		if (comFunc(min->val, node->bor->val) > 0)
		{
			pre = node;
			min = node->bor;
		}
		node = node->bor;
	}

	if (pre == nullptr&&min->bor == nullptr)
	{
		root = min->child;
	}
	else if (pre == nullptr)
	{
		node = min->child;
		root = min->bor;
		
	}
	else {
		pre->bor = min->bor;
		node = min->child;
	}

	//消除孩子和将要删除目标的依赖关系
	while (node != nullptr)
	{
		node->par = nullptr;
		node = node->bor;
	}

	root = merge(root, min->child);
	delete min;
	num--;
	return true;
}
template<class T>
T BinomialHeap<T>::top()
{
	if (empty()) throw "The heap is Empty";

	BinomialNode<T>* node = root;
	BinomialNode<T>* min = node;
	while (node != nullptr)
	{
		if (comFunc(node->val, min->val) < 0) min = node;
		node = node->bor;
	}
	return min->val;
}
template<class T>
bool BinomialHeap<T>::update(T oldVal, T newVal)
{
	if (comFunc(oldVal, newVal) == 0) return true;
	BinomialNode<T> *node = find(oldVal);
	node->val = newVal;
	if (comFunc(oldVal, newVal) > 0)
	{

		//新值更小
		up(node);
	}
	else
	{
		//新值更大
		down(node);
	}

	return false;
}
template<class T>
void BinomialHeap<T>::merge(BinomialHeap<T>& heap)
{
	BinomialNode<T>* copyh = copy(heap.root,nullptr);

	//合并两个堆
	root = merge(root, copyh);
	num += heap.num;
}
template<class T>
bool BinomialHeap<T>::empty()
{
	return num == 0;
}
template<class T>
void BinomialHeap<T>::push(T val)
{
	if (root == nullptr)
	{
		root = new BinomialNode<T>;
		root->val = val;
	}
	else
	{
		BinomialNode<T>*node = new BinomialNode<T>;
		node->val = val;
		root = merge(node, root);
	}
	num++;

}
template<class T>
void BinomialHeap<T>::print()
{
	if (root == nullptr) return;
	queue<BinomialNode<T>*> que;
	que.push(root);

	while (!que.empty())
	{
		BinomialNode<T>*node = que.front();
		que.pop();
		while (node != nullptr)
		{
			cout << node->val << " ";
			if (node->child != nullptr) que.push(node->child);
			node = node->bor;
		}
		cout << endl;
	}
}
template<class T>
void BinomialHeap<T>::clear(BinomialNode<T>* node)
{
	if (node == nullptr) return;
	queue<BinomialNode<T>*> container;
	BinomialNode<T>* tmp;
	container.push(root);

	while (!container.empty())
	{
		BinomialNode<T>*node = container.front();
		container.pop();
		while (node != nullptr)
		{
			tmp = node->bor;
			if (node->child != nullptr)
				container.push(node->child);
			delete node;
			node = tmp;
		}
	}

}

template<class T>
BinomialNode<T>* BinomialHeap<T>::find(T val)
{
	if (root == nullptr) return nullptr;
	queue<BinomialNode<T>*> container;
	container.push(root);
	while (!container.empty())
	{
		BinomialNode<T>*node = container.front();
		container.pop();
		while (node != nullptr)
		{
			if (node->child != nullptr)
				container.push(node->child);
			if (comFunc(node->val, val) == 0) return node;
			node = node->bor;
		}
	}

	return nullptr;
}

template<class T>
BinomialNode<T>* BinomialHeap<T>::merge(BinomialNode<T>* node1, BinomialNode<T>* node2)
{
	if (node1 == nullptr) return node2;
	if (node2 == nullptr) return node1;

	BinomialNode<T>* list = sortByDegree(node1, node2);

	if (list->bor == nullptr)
	{
		throw("排序的结果只有一个节点\n");
		return nullptr;
	}

	BinomialNode<T>* x = list;
	BinomialNode<T>* next_x = list->bor;
	BinomialNode<T>* pre_x = nullptr;
	BinomialNode<T>* head = x->deg == next_x->deg ? comFunc(x->val, next_x->val)<0 ? x : next_x : x;

	while (x->bor != nullptr)
	{
		if ((x->deg != next_x->deg) || ((pre_x != nullptr) && pre_x->deg == x->deg))
		{
			//当度数不相等或者是连续三个节点的度数相等的时候执行
			pre_x = x;
			x = next_x;
			next_x = next_x->bor;
		}
		else if (comFunc(x->val, next_x->val) < 0)
		{
			//当前的值比较小
			BinomialNode<T>*child = x->child;
			x->bor = next_x->bor;
			x->child = next_x;
			next_x->par = x;
			next_x->bor = child;
			x->deg++;
			next_x = x->bor;
		}
		else
		{
			//当前的值比较大
			BinomialNode<T>* child = next_x->child;
			if (pre_x != nullptr) pre_x->bor = next_x;
			else head = next_x;
			next_x->child = x;
			x->bor = child;
			x->par = next_x;
			next_x->deg++;
			x = next_x;
			next_x = x->bor;
		}
	}

	return head;
}

template<class T>
BinomialNode<T>* BinomialHeap<T>::copy(BinomialNode<T>* node, BinomialNode<T>*par)
{
	if (node == nullptr) return nullptr;

	vector<BinomialNode<T>*> arr;
	BinomialNode<T> tmp;
	BinomialNode<T> *list = &tmp;
	BinomialNode<T>* x = node;
	while (x != nullptr)
	{
		list->bor = new BinomialNode<T>();
		list = list->bor;
		list->val = x->val;
		list->deg = x->deg;
		list->par = par;
		list->child = copy(x->child, list);
		x = x->bor;
	}

	return tmp.bor;
}

template<class T>
BinomialNode<T>* BinomialHeap<T>::sortByDegree(BinomialNode<T>* u, BinomialNode<T>*v)
{

	if (u == nullptr) return v;
	if (v == nullptr) return u;
	BinomialNode<T>* ro;
	BinomialNode<T> *list;
	BinomialNode<T> tmp;//中介
	list = &tmp;
	ro = &tmp;


	while (u != nullptr&&v != nullptr)
	{
		if (u->deg > v->deg)
		{
			list->bor = v;
			v = v->bor;
			list = list->bor;
		}
		else
		{
			list->bor = u;
			u = u->bor;
			list = list->bor;
		}
	}

	if (u == nullptr) list->bor = v;
	if (v == nullptr) list->bor = u;

	return ro->bor;
}

template<class T>
void BinomialHeap<T>::up(BinomialNode<T>* node)
{
	if (node->par == nullptr) return;
	//向上走

	while (node->par != nullptr&&comFunc(node->val, node->par->val)<0)
	{
		T val = node->val;
		node->val = node->par->val;
		node->par->val = val;
		node = node->par;
	}
}

template<class T>
void BinomialHeap<T>::down(BinomialNode<T>* node)
{
	if (node->child == nullptr) return;

	BinomialNode<T>* child = node->child;
	BinomialNode<T>* min = child;
	while (child != nullptr)
	{
		if (comFunc(child->val, min->val) < 0) min = child;
		child = child->bor;
	}

	if (comFunc(node->val, min->val) < 0) return;

	T val = min->val;
	min->val = node->val;
	node->val = val;
	down(min);
}
