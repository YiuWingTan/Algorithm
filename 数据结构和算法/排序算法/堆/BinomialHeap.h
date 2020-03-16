#pragma once

#ifndef  _BINOMIALHEAP_H_

#define _BINOMIALHEAP_H_

/*����ѵ�ʵ��*/

//ֻ�����ڸ��ļ���ʹ�õ�����
template<class T>
 struct BinomialNode
{
	T val;
	int deg;//�ڵ�Ķ���
	BinomialNode<T> *par;//���ڵ�
	BinomialNode<T> *bor;//�ֵܽڵ�
	BinomialNode<T> *child;//���ӽڵ�
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
	void clear();//�������
	bool pop();//����һ��ֵ
	T top();//��ȡ��ߵ�ֵ
	bool update(T oldVal,T newVal);//����һ���ڵ��ֵ
	void merge(BinomialHeap<T>&heap);//�ϲ�������
	bool empty();
	void push(T val);
	void print();
private:
	int num;
	Compare comFunc;
	BinomialNode<T> *root;//���ڵ�
	void clear(BinomialNode<T>*node);
	BinomialNode<T>* find(T val);
	BinomialNode<T>* merge(BinomialNode<T>*node1,BinomialNode<T>*node2);
	BinomialNode<T>* copy(BinomialNode<T>*node, BinomialNode<T>*par);//����һ�������
	BinomialNode<T>* sortByDegree(BinomialNode<T>* u, BinomialNode<T>*v);//���ն�����������
	void up(BinomialNode<T>*node);
	void down(BinomialNode<T>*node);
};



#endif // ! _BINOMIALHEAP_H_


