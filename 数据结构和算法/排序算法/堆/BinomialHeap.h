#pragma once

#ifndef  _BINOMIALHEAP_H_

#define _BINOMIALHEAP_H_

/*二项堆的实现*/

//只允许在该文件中使用的类型
template<class T>
 struct BinomialNode
{
	T val;
	int deg;//节点的度数
	BinomialNode<T> *par;//父节点
	BinomialNode<T> *bor;//兄弟节点
	BinomialNode<T> *child;//孩子节点
	BinomialNode() :deg(0),par(nullptr),bor(nullptr),child(nullptr)
	{
	}
};

template<class T>
class BinomialHeap
{
public:
	typedef int(*Compare)(T, T);
	BinomialHeap(Compare func);
	BinomialHeap(const BinomialHeap<T>&heap);
	BinomialHeap<T>& operator=(const BinomialHeap<T>&heap);
	virtual ~BinomialHeap();
	void clear();//清除函数
	bool pop();//弹出一个值
	T top();//获取最高的值
	bool update(T oldVal,T newVal);//更新一个节点的值
	void merge(BinomialHeap<T>&heap);//合并两个堆
	bool empty();
	void push(T val);
	void print();
private:
	int num;
	Compare comFunc;
	BinomialNode<T> *root;//根节点
	void clear(BinomialNode<T>*node);
	BinomialNode<T>* find(T val);
	BinomialNode<T>* merge(BinomialNode<T>*node1,BinomialNode<T>*node2);
	BinomialNode<T>* copy(BinomialNode<T>*node, BinomialNode<T>*par);//复制一个二项堆
	BinomialNode<T>* sortByDegree(BinomialNode<T>* u, BinomialNode<T>*v);//按照度数进行排序
	void up(BinomialNode<T>*node);
	void down(BinomialNode<T>*node);
};



#endif // ! _BINOMIALHEAP_H_


