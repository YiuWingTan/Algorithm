
#include<iostream>
#include<string>
#include<queue>
using namespace std;

char a[1000][1000];
int row, col;
int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};

void bfs(int i,int j)
{
	a[i][j] = '0';
	queue<int> que;
	que.push(i);
	que.push(j);

	while (!que.empty())
	{
		int n = que.front(); que.pop();
		int m = que.front(); que.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = n + dirx[i];
			int y = m + diry[i];


			if (x < 0 || x >= row) continue;
			if (y < 0 || y >= col) continue;

			if (a[x][y] == '1')
			{
				a[x][y] = '0';
				que.push(x); que.push(y);

			}
		}
	}

 }


int main()
{
	
	cin >> row >> col;

	int count = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cin >> a[i][j];
	}



	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] == '1')
			{
				count++;
				bfs(i,j);
			}
		}
	}

	cout << count << endl;

	return 0;
}
