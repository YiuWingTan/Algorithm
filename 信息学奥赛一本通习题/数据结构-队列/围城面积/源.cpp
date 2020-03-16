
/*
解题思路：
首先只有被围住的0才算进面积中，在边界的零不算在面积中，我们首先给最外层上-1，只在最外层处使用bfs

*/


#include<iostream>
#include<string>
#include<queue>
using namespace std;

int a[10][10];
int dirx[] = { 0,0,1,-1 };
int diry[] = { 1,-1,0,0 };

void bfs(int i, int j)
{
	a[i][j] = -1;
	queue<int> que;
	que.push(i);
	que.push(j);


	while (!que.empty())
	{
		int x = que.front(); que.pop();
		int y = que.front(); que.pop();

		for (int n = 0; n < 4; n++)
		{
			int tmpi = x + dirx[n];
			int tmpj = y + diry[n];

			if (tmpi < 0 || tmpi >= 10) continue;
			if (tmpj < 0 || tmpj >= 10) continue;

			if (a[tmpi][tmpj] == 0)
			{
				a[tmpi][tmpj] = -1;
				que.push(tmpi);
				que.push(tmpj);
			}

		}


	}

}


int main()
{
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> a[i][j];
		}
	}

	
	for (int i = 0; i < 10; i++)	if(a[i][0]!=1)bfs(i, 0);
	for (int i = 0; i < 10; i++)	if (a[i][9] != 1)bfs(i, 9);
	for (int i = 0; i < 10; i++)	if (a[0][i] != 1)bfs(0, i);
	for (int i = 0; i < 10; i++)	if (a[9][i] != 1)bfs(9, i);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] == 0) count++;
		}
	}

	cout << count<<endl;

	
	return 0;
}
