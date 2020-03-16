
#include<iostream>
#include<cstdio>
using namespace std;


int group[1000];



int main()
{

	int num = 0;
	int n;
	
	while (cin >> n)
	{
		int k = num;
		int min = 50000;
		for (int i = 0; i < num; i++)
		{
			if (group[i] < min&&group[i] >= n)
			{
				k = i;
				min = group[i];
			}
		}

		group[k] = n;
		if (k == num) num++;
	}

	cout << num<<endl;

	return 0;
}


