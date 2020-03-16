
#include<iostream>
#include<queue>
using namespace std;

struct Point
{
	short x, y;
};
short dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
char m[1000][1000];
Point arr[100000];


void bfs(short x,short y,short r,short c)
{
	short current = 0, end = 1;
	arr[0] = {x,y};
	m[x][y] = '0';
	while (current != end)
	{
		
		for (int i = 0; i < 4; i++)
		{
			short tx = arr[current].x + dir[i][0], ty = arr[current].y + dir[i][1];
			if (tx < 0 || tx >= r || ty < 0 || ty >= c) continue;
			if (m[tx][ty] != '0')
			{
				m[tx][ty] = '0';
				arr[end++] = {tx,ty};
			}
		}
		current++;
	}
}


int main()
{
	int count = 0;
	int r, l;
	cin >> r >> l;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cin >> m[i][j];
		}
	}


	for (short i = 0; i < r; i++)
	{
		for (short j = 0; j < l; j++)
		{
			if (m[i][j] != '0')
			{
				bfs(i,j,r,l);
				count++;
			}
		}
	}

	cout << count << endl;


	return 0;
}



