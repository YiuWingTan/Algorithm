
#include<iostream>
using namespace std;

int n, k;
int num;

int r[10],c[10];
char mm[10][10];

void place(int m,int si)
{
	if (m > k)
	{
		num++;
		return;
	}


	for (int i = si; i < n; i++)
	{
		//if (r[i]) continue;

		for (int j = 0; j < n; j++)
		{
			if (c[j]|| mm[i][j] == '.') continue;

			mm[i][j] = '.';
			r[i] = 1;
			c[j] = 1;

			place(m+1,i+1);


			r[i] = 0;
			c[j] = 0;
			mm[i][j] = '#';
		}

	}


}


int main()
{

	while (cin >> n >> k)
	{
		if (n == -1 && k == -1) break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mm[i][j];
			}
		}

		place(1,0);

		cout << num << endl;
		num = 0;
	}


	return 0;
}



























