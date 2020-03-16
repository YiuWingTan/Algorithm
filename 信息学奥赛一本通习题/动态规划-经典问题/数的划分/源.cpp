

#include<iostream>
using namespace std;

int result;

/* �ݹ����� */
void count(int n,int k,int p)
{
	if (k == 1)
	{
		if (n >= p) result++;
		return;
	}

	for (int i = p; i <= n / k; i++)
	{
		count(n-i,k-1,i);
	}

}

/*��̬�滮����*/
/*���ǽ�n��С��ŵ�k�������У�f[k][n] = k�����������е�С�����������1 + k��������ֻ��һ��С��Ϊ1*/
int f[7][201];
int dp(int n,int k)
{
	f[0][0] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = f[i][j-i] + f[i-1][j-1];
		}
	}
	
	return f[k][n];
}



int main()
{
	int n, k;
	cin >> n >> k;
	count(n, k, 1);
	cout << result<<endl;


	return 0;
}

