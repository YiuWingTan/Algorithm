#include<iostream>
#include<queue>
#include<stdio.h>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


struct Point
{
	int k,i,j;
};

char m[100][100][100];

Point dirs[6] = 
{
	{0,1,0}
	,{0,-1,0}
	,{0,0,1}
	,{0,0,-1}
	,{1,0,0}
	,{-1,0,0}
};

int bfs(Point start,Point end,int d,int r,int c)
{
	int num = 1;
	int count = 1;
	queue<Point> que;
	que.push(start);
	m[start.k][start.i][start.j] = '#';

	while (!que.empty())
	{
		Point p = que.front(); que.pop();
		for (int i = 0; i < 6; i++)
		{
			int _k = p.k + dirs[i].k;
			int _i = p.i + dirs[i].i;
			int _j = p.j + dirs[i].j;

			//判断越界
			if (_k < 0 || _k >= d || _i < 0 || _i >= r || _j < 0 || _j >= c) continue;

			if (m[_k][_i][_j] != '#')
			{
				//判断是否为终点
				if (m[_k][_i][_j] == 'E') return count;

				que.push({_k,_i,_j});
				m[_k][_i][_j] = '#';
			}

		}

		if (--num <= 0)
		{
			num = que.size();
			count++;
		}
	}

	return -1;
}

int main() {

	vector<int> re;
	Point start, end;
	int d, r, c;
	
	while (cin >> d >> r >> c)
	{
		if (d == 0 && r == 0 && c == 0) break;
		for (int k = 0; k < d; k++)
		{
			for (int i = 0; i < r; i++)
			{

				for (int j = 0; j < c; j++)
				{
					cin >> m[k][i][j];

					if (m[k][i][j] == 'S')
					{
						start = { k,i,j };
					}
					else if (m[k][i][j] == 'E')
					{
						end = { k,i,j };
					}
				}

			}
		}

		int count = bfs(start, end, d, r, c);

		re.push_back(count);
	}

	
	for (int i = 0; i < re.size(); i++)
	{
		if (re[i] != -1){

			printf("Escaped in %d minute(s).\n",re[i]);

		}
		else {

			printf("Trapped!\n");

		}
	}

	return 0;
}





