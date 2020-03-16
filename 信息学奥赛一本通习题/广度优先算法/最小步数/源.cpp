
#include<iostream>
#include<queue>
using namespace std;


struct Point
{
	int i, j;
};

int board[101][101];

Point dirs[12] = 
{
	{-1,2},
	{1,2},
	{2,2},
	{2,1},
	{2,-1}
	,{2,-2}
	,{1,-2}
	,{-1,-2}
	,{-2,-2}
	,{-2,-1}
	,{-2,1}
	,{-2,2}
};


int bfsFind(Point pos, int mark)
{
	int count = 1;
	int num = 1;
	queue<Point> que;
	que.push(pos);
	board[pos.i][pos.j] = mark;

	while (!que.empty())
	{
		
		Point& point = que.front(); que.pop();
		for (int i = 0; i < 12; i++)
		{
			int tx = dirs[i].i+point.i;
			int ty = dirs[i].j + point.j;

			//ÅÐ¶ÏÊÇ·ñÔ½½ç
			if (tx < 1 || tx > 100 || ty < 1 || ty > 100) continue;

			if (tx == 1 && ty == 1) 
				return count;

			if (board[tx][ty] != mark)
			{
				board[tx][ty] = mark;
				que.push({tx,ty});
			}
		}
		if (--num == 0)
		{
			num = que.size();
			count++;
		}
	}

	return -1;
}

int main()
{
	Point p1;
	Point p2;

	cin >> p1.i >> p1.j;
	cin >> p2.i >> p2.j;

	int n = bfsFind(p1,1);
	int m = bfsFind(p2,2);
	cout << m << endl;
	cout << n << endl;
	

	return 0;
}



