#include<queue>
#include<iostream>
using namespace std;

struct Point
{
	int i, j;
};

int dirs[4][3] = { {0,1,4},{0,-1,1},{1,0,8},{-1,0,2} };
int m[50][50];

int  bfs(int i,int j,int N,int M)
{
	int count = 1;

	queue<Point> que;
	que.push({i,j});
	m[i][j] +=16;//第四位上1

	while (!que.empty())
	{
		Point p = que.front(); que.pop();
		for (int i = 0; i < 4; i++)
		{
			int _i = p.i + dirs[i][0];
			int _j = p.j + dirs[i][1];

			if (_i < 0 || _i >= N || _j < 0 || _j >= M||(m[_i][_j] & 16)) continue;

			//判断该方向上是否有墙
			if ((dirs[i][2] & m[p.i][p.j])== 0)
			{
				//没有墙
				m[_i][_j] += 16;
				que.push({_i,_j});
				count++;
			}
		}

	}


	return count;
}


int main()
{
	int N, M;
	cin >> N >> M;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> m[i][j];
		}
	}

	int max = 0;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((m[i][j] & 16)== 0)
			{
				//房间还没有被走过
				count++;
				int tmp = bfs(i,j,N,M);
				if (tmp > max) max = tmp;
			}
		}
	}


	cout << count << endl;
	cout << max << endl;

	return 0;
}



