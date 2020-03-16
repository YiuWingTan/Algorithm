

#include<iostream>

using namespace std;

int a[9],b[9],c[18],d[18];

void print()
{
	static int number = 1;


	cout << "No. " << number++ << endl;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{

			if (a[j] == i)
				cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}
	
}

void search(int n)
{
	if (n > 8)
	{
		print();
		return ;
	}


	for (int i = 1; i <= 8; i++)
	{
		if ((!b[i])&&(!c[n + i])&&(!d[n - i + 7]))
		{
			a[n] = i;
			b[i] = 1;
			c[n + i] = 1;
			d[n - i+7] = 1;

			search(n+1);
			//a[n] = 0;
			b[i] = 0;
			c[n + i] = 0;
			d[n - i + 7] = 0;
		}
	}


}



int main()
{

	search(1);



	return 0;
}



