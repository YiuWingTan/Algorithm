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

	cout << "��������ӵĳ���:";
	cin >> l;

	cout << "���������ϵ�����:";
	cin >> n;

	int *target = new int[n];
	int mint = 0, maxt = 0;
	cout << "���������ϵľ���"<<endl;

	for (int i = 0; i < n; i++)
	{
		cin >> target[i];
	}

	for (int i = 0; i < n; i++)
	{
		mint = max(mint,min(l - target[i],target[i]));
		maxt = max(maxt,max(l - target[i],target[i]));
	}

	cout << "����ʱ����"<<maxt<<endl;

	cout << "��С��ʱ���ǣ�" << mint << endl;


	system("pause");

    return 0;
}

