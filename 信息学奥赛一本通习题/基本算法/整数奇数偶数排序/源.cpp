#include<iostream>
#include<vector>

using namespace std;

int a[20];

int main()
{

	for (int i = 1; i <=10; i++)
	{
		cin >> a[i];
	}


	for (int i = 1; i <= 10; i++)
	{

		for (int j = 2; j <= 10; j++)
		{
			if (a[j - 1] % 2 == 0 && a[j] % 2 != 0)
			{
				swap(a[j-1],a[j]);
			}
			else if (a[j - 1] % 2 == 0 && a[j] % 2 == 0&&a[j-1]>a[j])
			{
				//都是偶数
				swap(a[j - 1], a[j]);
			}
			else if (a[j - 1] % 2 != 0 && a[j] % 2 != 0 && a[j - 1]<a[j])
			{
				//都是奇数
				swap(a[j - 1], a[j]);
			}
		}


	}

	for (int i = 1; i <= 10; i++)
		cout << a[i]<<" ";
	cout << endl;


	//system("pause");
	return 0;
}


