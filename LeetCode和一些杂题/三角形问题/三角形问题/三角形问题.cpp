// ����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>

using namespace std;

inline bool isTrangle(int a,int b,int c)
{
	if (a + b > c&&b + c > a&&a + c > b) return true;

	return false;
}

int main()
{
	int n;

	int result = 0;
	
	cout << "������ӵ���Ŀ��";
	cin >> n;
	int *target = new int[n];

	for (int i = 0; i < n; i++)
		cin>>target[i];

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (isTrangle(target[i], target[j], target[k]))
				{
					result = result < (target[i]+target[j]+ target[k]) ? (target[i] + target[j] + target[k]): result;
				}
			}
		}
	}

	cout << "���Ϊ"<<result;

	getchar();

	system("pause");

    return 0;
}

