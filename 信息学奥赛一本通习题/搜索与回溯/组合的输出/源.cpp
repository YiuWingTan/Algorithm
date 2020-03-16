


#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;


bool b[21];
int a[21];

void print(int r)
{

	for (int i = 0; i < r; i++)
	{
		cout << setw(3) << a[i];
	}
	cout << endl;
}


void search(int n,int r,int c,int j)
{
	if (c == r)
	{
		print(r);
		return;
	}

	for (int i = j; i <= n; i++)
	{
		if (!b[i])
		{
			a[c] = i;
			b[i] = true;

			search(n,r,c+1,i+1);

			b[i] = false;

		}
	}
}





int main()
{
	int n, r;
	cin >> n >> r;


	search(n,r,0,1);


	return 0;
}

