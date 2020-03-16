#pragma once
#ifndef LEFTISTHEAP_H_
#define LEFTISTHEAP_H_

#include<vector>

//����ѵĽڵ�����
template<class T>
 struct  LHNode
{
	T val;
	int npl;//�����
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

//�����Ҳ��������
template<class T>
class LeftistHeap
{
private:
	LHNode<T> *root;//���ڵ�
	int size;//���нڵ�ĸ���
	bool isdelete;


	LHNode<T>* createCopy(LHNode<T>* node);//����һ������
	void initByVector(const std::vector<T> &arr);
	LHNode<T>* merge(LHNode<T>*x,LHNode<T>*y);
	void destory(LHNode<T>* node);
	void preOrder(LHNode<T>*node,std::vector<T>&arr);
	void midOrder(LHNode<T>*node,std::vector<T>&arr);
	void backOrder(LHNode<T>*node,std::vector<T>&arr);
public:
	LeftistHeap();
	LeftistHeap(const std::vector<T>&arr);
	LeftistHeap(const LeftistHeap<T>&object);//ɾ�����ƹ��캯��
	LeftistHeap<T>& operator=(const LeftistHeap&object);//ɾ�� =���������
	virtual ~LeftistHeap();


	T top();
	void merge(LeftistHeap<T>tree);//�ϲ�
	void pop();//ɾ����С��Ԫ��
	void insert(T val);//����
	void destroy();//���������
	bool empty();
	void printfLeftistHeap();//��ӡ
	void preOrder(std::vector<int>&arr);//ǰ��
	void midOrder(std::vector<int>&arr);//����
	void backOrder(std::vector<int>&arr);//����
	int count();
};


#endif // !LEFTISTHEAP_H_


