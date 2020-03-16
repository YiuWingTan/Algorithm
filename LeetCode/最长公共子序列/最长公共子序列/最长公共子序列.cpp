#include<iostream>
#include<string>
using namespace std;
int **length;
int n, m;
string a, b;
inline int max(int i, int j)
{
	return i > j ? i : j;
}

inline void solve()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=m; j++)
		{
			if (a[i] == b[j])
			{
				length[i][j] = length[i - 1][j - 1] + 1;
			}
			else

			{
				length[i][j] = max(length[i-1][j],length[i][j-1]);
			}
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;
	length = new int*[n+1];
	for (int i = 0; i <=n; i++)
	{
		length[i] = new int[m+1];

		for (int j = 0; j <=m; j++)
		{
			length[i][j] = 0;
		}
	}
	cout << "请输入两个字符串的长度"<<endl;
	getchar();
	getline(cin,a);
	getline(cin,b);

	/*cout << a << endl;
	cout << b << endl;*/

	solve();

	cout << "两个字符串的最长子序列长度是:"<<length[n][m]<<endl;


	system("pause");
    return 0;
}

