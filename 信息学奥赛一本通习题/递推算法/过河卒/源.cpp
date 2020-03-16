/*
【问题描述】
棋盘上A点有一个过河卒，需要走到目标B点。卒行走的规则：可以向下、或者向右。同时在棋盘上的任一点有一个对方的马（如C点）
，该马所在的点和所有跳跃一步可达的点称为对方马的控制点，如图3-1中的C点和P1，……，P8，
卒不能通过对方马的控制点。棋盘用坐标表示，A点(0,0)、B点(n, m) (n,m为不超过20的整数),同样马的位置坐标是需要给出的
，C≠A且C≠B。现在要求你计算出卒从A点能够到达B点的路径的条数。

【算法分析】

递归，或者是动态规划


*/


#include<iostream>

using namespace std;

long long board[21][21];


int main()
{

	int n, m;
	cin >> n >> m;

	int x, y;
	cin >> x >> y;
	int dx = 1;
	int dy = 2;
	
	board[0][0] = 1;
	board[x][y] = -1;
	for (int i = 0; i < 4;i++)
	{
		if (i == 2) std::swap(dx,dy);

		if (x + dx >= 0 && x + dx <= n)
		{
			if (y + dy >= 0 && y + dy <= m)
			{
				board[x + dx][y + dy] = -1;
			}
			if (y - dy >= 0 && y - dy <= m)
			{
				board[x + dx][y - dy] = -1;
			}
		}
		dx *= -1; dy *= -1;
	}
	
	//初始化最上，和最左

	for (int j = 1; j <= m; j++) {
		if (board[0][j] != -1) board[0][j] += board[0][j - 1];
		else board[0][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (board[i][0] != -1) board[i][0] += board[i-1][0];
		else board[i][0] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == -1) {
				board[i][j] = 0;
				
			}
			else
			board[i][j] = board[i - 1][j]+board[i][j-1];
		}
	}

	cout << board[n][m] << endl;
	//system("pause");
	return 0;
}