
#include<iostream>
#include<queue>
using namespace std;

int dirs[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
struct Point
{
	int i, j;
};

char m[110][110];


void bfs(int i,int j,int N,int M)
{
	queue<Point> que;
	que.push({i,j});
	m[i][j] = '.';

	while (!que.empty())
	{
		Point p = que.front(); que.pop();
		for (int i = 0; i < 8; i++)
		{
			int _i = dirs[i][0]+ p.i;
			int _j = dirs[i][1] + p.j;

			if (_i < 0 || _i >= N || _j < 0 || _j >= M) continue;


			if (m[_i][_j] != '.')
			{
				m[_i][_j] = '.';
				que.push({_i,_j});
			}
		}
	}




}


int main()
{
	int count = 0;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			cin >> m[i][j];

		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (m[i][j] == 'W')
			{
				bfs(i,j,N,M);
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}







