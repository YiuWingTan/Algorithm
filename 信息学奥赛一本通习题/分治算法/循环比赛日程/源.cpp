
#include<iostream>

using namespace std;

int n = 1;
int cont[1000][1000];


void generate(int k)
{
	if (k == 1) return;

	generate(k/2);

	for (int w = 0; w < n; w += k)
	{
		for (int i = 0; i < k / 2; i++)
		{
			for (int j = 0; j < k / 2; j++)
			{

				cont[i + k / 2][w+j + k / 2] = cont[i][j+w];
			}
		}

		for (int i = 0; i < k / 2; i++)
		{
			for (int j = k / 2; j < k; j++)
			{
				cont[i + k / 2][j - k / 2+w] = cont[i][j+w];
			}
		}


	}
}


int main()
{
	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
		n *= 2;
	//³õÊ¼»¯¾ØÕó
	for (int i = 0; i <n; i++)
		cont[0][i] = i + 1;

	generate(n);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			cout << cont[i][j]<<" ";
		}
		cout << endl;
	}


	return 0;
}

