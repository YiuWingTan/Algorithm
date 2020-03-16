
#include"二叉查找树.h"
#include<iostream>
#include"红黑树.h"
using namespace std;

//二分查找
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
		cout << "相等的索引是：" << index << " 相等的值是:" << a[index]<<endl;
	else

		cout << "没有找到相应的值，数组中没有这样的值\n";


	cout << "开始测试二叉查找树\n";
	int keys[10];
	int values[10];
	cout << "请输入建表:";
	for (int i = 0; i < 10; i++)
	{
		cin >> keys[i];
	}
	cout << "请输入值表:";
	for (int i = 0; i < 10; i++)
	{
		cin >> values[i];
	}

	cout << "键为:";
	for (int i = 0; i < 10; i++)
	{
		cout << keys[i]<<" ";
	}
	cout << endl;

	cout << "值为:";
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
		cout << "请输入查找的键值:";
		cin >> key;
		system("CLS");
		if (key < 0) break;

		
		cout << "现在二叉查找树中的值为 ";
		t.PreOrder();
		cout << endl;
		cout << "现在红黑树中的值为 ";
		rt.PreOrder();
		cout << endl;

		int value = t.Get(key);
		int v = rt.Get(key);

		if (value != -1)
			cout << "二叉查找树查找到的键值为" << value << endl;
		else
			cout << "二叉查找树没有找到这样的值\n";
		if (v != -1)
			cout << "红黑树查找到的键值为:" << v << endl;
		else
			cout << "红黑树没有找到这样的值\n";

		rt.DeleteMin();
		rt.DeleteMax();

	}


	getchar();
	getchar();
    return 0;
}

