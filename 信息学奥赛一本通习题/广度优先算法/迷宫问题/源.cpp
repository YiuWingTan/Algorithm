#include<queue>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Point {

	int i, j;

};

int dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int arr[5][5];

Point parent[5][5];

void bfs()
{
	queue<Point> que;
	que.push({ 0,0 });
	arr[0][0] = -1;

	while (!que.empty())
	{
		Point& p = que.front(); que.pop();

		for (int i = 0; i < 4; i++)
		{
			int _i = p.i + dirs[i][0];
			int _j = p.j + dirs[i][1];

			if (_i < 0 || _i >= 5 || _j < 0 || _j >= 5||arr[_i][_j] == 1) continue;

		
			if (arr[_i][_j] != -1)
			{
				//¼ÇÂ¼¸¸½Úµã
				parent[_i][_j] = p;
				if (_i == 4 && _j == 4) return;

				arr[_i][_j] = -1;
				que.push({_i,_j});
			}

		}

	}
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			cin >> arr[i][j];
		}
	}
	parent[0][0] = {-1,-1};

	bfs();

	vector<Point> path;
	int i = 4, j = 4;
	while (i != -1 && j != -1)
	{
		path.push_back({i,j});
		Point&p = parent[i][j];
		i = p.i;
		j = p.j;
	}

	for (int i = path.size() - 1;i >= 0; i--)
	{
		printf("(%d, %d)\n",path[i].i,path[i].j);
	}


	return 0;
}


