#include<iostream>
#include<vector>
#include"Heap.h"
#include"Heap.cpp"
#include"LeftistHeap.h"
#include"LeftistHeap.cpp"
#include"BinomialHeap.h"
#include"BinomialHeap.cpp"
using namespace std;

bool sinkC(int i,int j)
{
	return i > j?true:false;
}

bool swimC(int i,int j)
{

	return i < j?true: false;
}

int smaller(int u,int v)
{
	return u - v;
}

//��������
void textInput()
{
	Heap<int> heap(sinkC, swimC);

	int val = 1;
	while (val != 0)
	{
		printf("������Ҫ���뵽���е�����\n");
		cin >> val;
		heap.insert(val);
		heap.show();
		printf("�Ѷ�Ϊ%d\n\n", heap.top());
	}
}

//����ɾ��
void textDel()
{
	vector<int> arr = {2,3,6,-9,58,15,1,5,15,1,5,-1,-44,-33,9,5,14,8};

	Heap<int> heap(sinkC,swimC);

	for (int i = 0; i < arr.size(); i++)
	{
		heap.insert(arr[i]);
	}
	printf("�ѵĳ�ʼ״̬Ϊ\n");
	heap.show();

	int index = 0;
	while (index >= 0)
	{
		printf("������Ҫ����ɾ���������� ");
		cin >> index;
		if (index < 0) break;
		heap.del(index);
		printf("�Ѷ�Ϊ%d\n�ѵ�״̬Ϊ\n",heap.top());
		heap.show();
		cout << endl;
	}

}


//���������
void textLeftistHeap()
{
	vector<int> arr1 = {5,6,3,2,15,5,8,7,4,26};
	vector<int> arr2 = {3,6,2,5,1,148,9,6};

	LeftistHeap<int> heap1(arr1);
	LeftistHeap<int> heap2(arr2);

	heap1.printfLeftistHeap();
	heap2.printfLeftistHeap();
	cout << heap1.count() << endl;
	heap1.merge(heap2);
	heap1.printfLeftistHeap();
	cout << heap1.count()<<endl;
	cout << endl;
	while (!heap1.empty())
	{
		cout << heap1.top()<<" ";
		heap1.pop();
	}

}


//���Զ����
void textBinomialHeap1()
{
	BinomialHeap<int> heap(smaller);

	int val = 1;

	while (val != -1)
	{
		cout << "����ֵ:";
		cin >> val;
		heap.push(val);
		heap.print();
		cout << "��Сֵ��"<<heap.top()<<endl<<endl;
		heap.pop();
	}
}

void textBinomialHeap2()
{
	BinomialHeap<int> heap(smaller);
	BinomialHeap<int> heap2(smaller);
	vector<int>arr1 = {-6,5,4,1,2,6,9,85,-89,-1};
	vector<int> arr2 = {7,8,9,-4,5,6,1,2,3};

	for (int i = 0; i < arr1.size(); i++)
		heap.push(arr1[i]);


	
	heap.print();
	//cout << endl;
	int val;
	int nval;
	cout << "������Ҫ���и��µ�ֵ: ";
	cin >> val;
	cout << "��������ֵ:";
	cin >> nval;
	heap.update(val,nval);
		
	cout << endl;

	while (!heap.empty())
	{
		cout << heap.top()<<" ";
		heap.pop();
	}

	
}

int main()
{
	
	textBinomialHeap2();

	getchar();
	getchar();
	return 0;
}
