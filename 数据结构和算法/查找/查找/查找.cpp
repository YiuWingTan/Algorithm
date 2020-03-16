
#include"���������.h"
#include<iostream>
#include"�����.h"
using namespace std;

//���ֲ���
inline int BinarySearch(int a[],int lo,int hi,int target)
{
	int k = 0;
	while (true)
	{
		k = (hi - lo) / 2 + lo;
		if (a[k] == target) return k;
		else if (lo == hi) return -1;
		else if (a[k] < target) lo = k+1;
		else hi = k;
	}
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,55,147,258,369,1478,11478};

	int index = BinarySearch(a,0,24, 11478);

	if (index != -1)
		cout << "��ȵ������ǣ�" << index << " ��ȵ�ֵ��:" << a[index]<<endl;
	else

		cout << "û���ҵ���Ӧ��ֵ��������û��������ֵ\n";


	cout << "��ʼ���Զ��������\n";
	int keys[10];
	int values[10];
	cout << "�����뽨��:";
	for (int i = 0; i < 10; i++)
	{
		cin >> keys[i];
	}
	cout << "������ֵ��:";
	for (int i = 0; i < 10; i++)
	{
		cin >> values[i];
	}

	cout << "��Ϊ:";
	for (int i = 0; i < 10; i++)
	{
		cout << keys[i]<<" ";
	}
	cout << endl;

	cout << "ֵΪ:";
	for (int i = 0; i < 10; i++)
	{
		cout << values[i]<<" ";
	}
	cout << endl;

	int key;

	BinaryTree t;
	RedBlackTree rt;

	for (int i = 0; i < 10; i++)
	{
		t.Put(keys[i], values[i]);
		rt.Put(keys[i], values[i]);
	}

	while (true)
	{
		//
		cout << "��������ҵļ�ֵ:";
		cin >> key;
		system("CLS");
		if (key < 0) break;

		
		cout << "���ڶ���������е�ֵΪ ";
		t.PreOrder();
		cout << endl;
		cout << "���ں�����е�ֵΪ ";
		rt.PreOrder();
		cout << endl;

		int value = t.Get(key);
		int v = rt.Get(key);

		if (value != -1)
			cout << "������������ҵ��ļ�ֵΪ" << value << endl;
		else
			cout << "���������û���ҵ�������ֵ\n";
		if (v != -1)
			cout << "��������ҵ��ļ�ֵΪ:" << v << endl;
		else
			cout << "�����û���ҵ�������ֵ\n";

		rt.DeleteMin();
		rt.DeleteMax();

	}


	getchar();
	getchar();
    return 0;
}

