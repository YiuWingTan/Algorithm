#pragma once

#ifndef _HEAP_H_
#define _HEAP_H_

#define Parent(i) (((i)-1)/2)//获取父节点

#define LEFT(i) (((i)*2)+1)//获取左节点
#define RIGHT(i) (((i)*2)+2)

#include<iostream>
using namespace std;

//二叉堆
template<class T>
class Heap
{
public:
	typedef bool(*Compare)(T,T);//定义比较函数
	

	Heap(Compare _sinkFunc,Compare _swimFunc);
	Heap(const Heap<T>&object);
	Heap<T>& operator=(const Heap<T> &object);
	~Heap();
	 void insert(T a);//插入数据
	 T top();//堆顶
	 void Pop();//弹出
	 bool del(int index);//指明索引进行删除操作
	 bool empty();
	 int count();
	 void show();//输出数组
private:
	 bool expand();
	 void swim(int i,int n);//向上移动
	 void sink(int i,int n);//向下移动
	 void swap(int i, int j);


	T *data;//数据
	Compare swinFunc;//上浮函数
	Compare sinkFunc;//下沉函数
	int size;
	int container;//当前数据的容量.
	
};



#endif // !_HEAP_H_


