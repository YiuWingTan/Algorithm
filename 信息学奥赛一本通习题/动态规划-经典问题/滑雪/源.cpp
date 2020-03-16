
#include<iostream>
using namespace std;

struct Path
{
	int i;
	int j;
};
int R, C;
int arr[101][101];
int dp[101][101];

Path paths[4] = { {0,1},{1,0},{-1,0},{0,-1} };

int max(int a, int b) { return a > b ? a : b; }

int search(int i,int j)
{

	
	if (dp[i][j] != 0) return dp[i][j];//���仯������ֹ�������ͬһ����

	int result = 0;

	for (int k = 0; k < 4; k++)
	{
		int x = paths[k].i + i;
		int y = paths[k].j + j;

		//��ֹԽ��
		if (x <= 0 || x > R || y <= 0 || y > C) continue;

		//�����ֳ��½������Ƶ�ʱ��Ž�������
		if (arr[x][y] > arr[i][j])
			result = max(search(x, y) + 1, result);
	}

	dp[i][j] = result == 0 ? 1 : result;

	return dp[i][j];

}

int main()
{
	
	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{

			cin >> arr[i][j];

		}
	}
	
	int result = 0;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			dp[i][j] = search(i, j);
			result = max(result,dp[i][j]);
			
		}
	}

	cout << result<<endl;

	return 0;
}

