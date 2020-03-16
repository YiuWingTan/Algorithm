#include<iostream>
#include<string>
using namespace std;

int n, m, num = 0;
inline bool constrain(int k,int i,int j)
{
	if (k <= j&&k >= i) return true;
	return false;
}

inline void search(char **s,int lo ,int hi)
{
	s[lo][hi] = '.';
	for (int i = lo - 1; i <= lo + 1; i++)
	{
		for (int j = hi - 1; j <= hi + 1; j++)
		{
			if (i == lo&&j == hi) continue;
			if (constrain(i,0,m-1)&&constrain(j,0,n-1))
			{
				if (s[i][j] == 'W')
				{
					 search(s, i, j);
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;
	char **str = new char*[m];
	getchar();
	for (int i = 0; i < m; i++)
		str[i] = new char[n];

	for (int i = 0; i < m; i++)
	{
		getchar();
		cin.getline(str[i], n);
	}
	cout << endl << endl;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cout << str[j][i] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[i][j] == 'W')
			{
				search(str, i, j);
				num++;
			}
		}
	}

	cout << num << endl;

	system("pause");

	getchar();
    return 0;
}

