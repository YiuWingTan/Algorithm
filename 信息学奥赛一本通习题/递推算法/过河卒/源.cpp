/*
������������
������A����һ�������䣬��Ҫ�ߵ�Ŀ��B�㡣�����ߵĹ��򣺿������¡��������ҡ�ͬʱ�������ϵ���һ����һ���Է�������C�㣩
���������ڵĵ��������Ծһ���ɴ�ĵ��Ϊ�Է���Ŀ��Ƶ㣬��ͼ3-1�е�C���P1��������P8��
�䲻��ͨ���Է���Ŀ��Ƶ㡣�����������ʾ��A��(0,0)��B��(n, m) (n,mΪ������20������),ͬ�����λ����������Ҫ������
��C��A��C��B������Ҫ�����������A���ܹ�����B���·����������

���㷨������

�ݹ飬�����Ƕ�̬�滮


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
	
	//��ʼ�����ϣ�������

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