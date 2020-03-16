
#include<iostream>

using namespace std;

int dist[201][201];

int val[201];
int lChild[201];
int rChild[201];


int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> val[i]>>lChild[i]>>rChild[i];

	//初始化距离
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (lChild[i] == j || rChild[i] == j)
			{
				dist[i][j] = dist[j][i] = 1;
			}else if(dist[i][j] == 0)
				dist[i][j] = 1000000;
		}
		dist[i][i] = 0;
	}


	//弗洛伊德算法
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	//找出最小值
	int minV = 10000000;


	for (int i = 1; i <= n; i++)
	{
		int v = 0;
		for (int j = 1; j <= n; j++)
		{
			v += val[j] * dist[i][j];
		}

		if (v < minV) minV = v;

	}

	cout << minV<<endl;

	return 0;
}
