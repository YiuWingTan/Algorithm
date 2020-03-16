#pragma once

#ifndef _HEAP_H_
#define _HEAP_H_

#define Parent(i) (((i)-1)/2)//��ȡ���ڵ�

#define LEFT(i) (((i)*2)+1)//��ȡ��ڵ�
#define RIGHT(i) (((i)*2)+2)

#include<iostream>
using namespace std;

//�����
template<class T>
class Heap
{
public:
	typedef bool(*Compare)(T,T);//����ȽϺ���
	

	Heap(Compare _sinkFunc,Compare _swimFunc);
	Heap(const Heap<T>&object);
	Heap<T>& operator=(const Heap<T> &object);
	~Heap();
	 void insert(T a);//��������
	 T top();//�Ѷ�
	 void Pop();//����
	 bool del(int index);//ָ����������ɾ������
	 bool empty();
	 int count();
	 void show();//�������
private:
	 bool expand();
	 void swim(int i,int n);//�����ƶ�
	 void sink(int i,int n);//�����ƶ�
	 void swap(int i, int j);


	T *data;//����
	Compare swinFunc;//�ϸ�����
	Compare sinkFunc;//�³�����
	int size;
	int container;//��ǰ���ݵ�����.
	
};



#endif // !_HEAP_H_


