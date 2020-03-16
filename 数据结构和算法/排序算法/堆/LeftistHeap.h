#pragma once
#ifndef LEFTISTHEAP_H_
#define LEFTISTHEAP_H_

#include<vector>

//左倾堆的节点类型
template<class T>
 struct  LHNode
{
	T val;
	int npl;//零距离
	LHNode<T>* left;
	LHNode<T>* right;
	LHNode(T _val, int _npl, LHNode<T>*_left, LHNode<T>*_right)
	{
		val = _val;
		npl = _npl;
		left = _left;
		right = _right;
	}
	LHNode<T>(){
		left = nullptr;
		right = nullptr;
	}
};

//左倾堆也叫左倾树
template<class T>
class LeftistHeap
{
private:
	LHNode<T> *root;//根节点
	int size;//树中节点的个数
	bool isdelete;


	LHNode<T>* createCopy(LHNode<T>* node);//创建一个副本
	void initByVector(const std::vector<T> &arr);
	LHNode<T>* merge(LHNode<T>*x,LHNode<T>*y);
	void destory(LHNode<T>* node);
	void preOrder(LHNode<T>*node,std::vector<T>&arr);
	void midOrder(LHNode<T>*node,std::vector<T>&arr);
	void backOrder(LHNode<T>*node,std::vector<T>&arr);
public:
	LeftistHeap();
	LeftistHeap(const std::vector<T>&arr);
	LeftistHeap(const LeftistHeap<T>&object);//删除复制构造函数
	LeftistHeap<T>& operator=(const LeftistHeap&object);//删除 =运算符函数
	virtual ~LeftistHeap();


	T top();
	void merge(LeftistHeap<T>tree);//合并
	void pop();//删除最小的元素
	void insert(T val);//插入
	void destroy();//销毁左倾堆
	bool empty();
	void printfLeftistHeap();//打印
	void preOrder(std::vector<int>&arr);//前序
	void midOrder(std::vector<int>&arr);//中序
	void backOrder(std::vector<int>&arr);//后序
	int count();
};


#endif // !LEFTISTHEAP_H_


