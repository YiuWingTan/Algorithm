#include<iostream>
#include<vector>
using namespace std;
int row;
int col;

//����ʱ������
int unp(int i,int j)
{
	if (i >= row || j >= col) return 0;
	if (i == (row - 1) && j == (col - 1)) return 1;
	return unp(i + 1, j) + unp(i,j+1);
}

//����ʱ������
int uniquePaths1(int m, int n) {

	row = m;
	col = n;
	return unp(0,0);

}


//��̬�滮-�Ե�����
int uniquePaths2(int m,int n)
{
	if (m == 0 || n == 0) return 0;
	vector<vector<int>> dp;
	dp.resize(m+1);
	for (int i = 0; i <=m; i++)
		dp[i].resize(n+1,0);

	dp[m - 1][n - 1] = 1;

	//�ʵ�����ڱ����Լ���������������

	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			dp[i][j] = dp[i][j] < (dp[i + 1][j] + dp[i][j + 1]) ? dp[i + 1][j] + dp[i][j + 1] : dp[i][j];
		}
	}

	return dp[0][0];
}

int main()
{
	int n = 2;
	int m = 3;
	int count = uniquePaths2(m,n);
	printf("�ܹ���%d��·��\n",m,n);
	getchar();
	return 0;
}