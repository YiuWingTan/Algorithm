#include<iostream>

using namespace std;

inline int max(int i, int j)
{
	return i > j ? i:j;
}

inline int min(int i,int j)
{
	return i < j ? i : j;
}

int main()
{
	int l,n;

	cout << "请输入杆子的长度:";
	cin >> l;

	cout << "请输入蚂蚁的数量:";
	cin >> n;

	int *target = new int[n];
	int mint = 0, maxt = 0;
	cout << "请输入蚂蚁的距离"<<endl;

	for (int i = 0; i < n; i++)
	{
		cin >> target[i];
	}

	for (int i = 0; i < n; i++)
	{
		mint = max(mint,min(l - target[i],target[i]));
		maxt = max(maxt,max(l - target[i],target[i]));
	}

	cout << "最大的时间是"<<maxt<<endl;

	cout << "最小的时间是：" << mint << endl;


	system("pause");

    return 0;
}

