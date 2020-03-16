
#include<iostream>
#include<stdio.h>
using namespace std;

char m[199999];
int n;
int sp;

long long number = 0;

void show()
{
	printf("step%2d:",number);
	for (int i = 1; i <= 2 * n + 2; i++)
	{
		cout << m[i];
	}
	number++;
	cout << endl;
}

void init()
{
	for (int i = 1; i <= 2 * n; i++)
	{
		if (i > n)
		{
			m[i] = '*';
		}
		else m[i] = 'o';
	}

	m[2 * n + 1] = '-';
	m[2 * n + 2] = '-';
	show();
}


void move(int k)
{
	for (int j = 0; j <= 1; j++)
	{

		swap(m[sp+j],m[k+j]);

	}
	sp = k;
	show();
}


void mv(int n)
{

	if (n == 4)
	{
		move(4); move(8); move(2); move(7); move(1);
	}
	else
	{
		move(n); move(2 * n - 1); mv(n-1);
	}
}

int main()
{
	
	cin >> n;
	sp = 2*n+1;
	init();
	mv(n);


	return 0;
}


