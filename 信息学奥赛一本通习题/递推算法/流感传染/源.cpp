/*
【题目描述】
有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。

【输入】
第一行一个数字n，n不超过100，表示有n*n的宿舍房间。

接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。

接下来的一行是一个整数m，m不超过100。

【输出】
输出第m天，得流感的人数。

【输入样例】
5
....#
.#.@.
.#@..
#....
.....
4
【输出样例】
16

*/


#include<iostream>
#include<vector>
using namespace std;

char a[100][100];

int main()
{

	int n,m,count = 0;
	vector<int> tmp;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>a[i][j];
			if (a[i][j] == '@') {
				count++;
				tmp.push_back(i);
				tmp.push_back(j);
			}
		}
	}

	cin >> m;

	
	for (int k = 1; k < m; k++)
	{
		int num = tmp.size();
		for (int c = 0; c < num; c+=2)
		{
			int i = tmp[c]; int j = tmp[c + 1];

			if (i - 1 >= 0 && a[i - 1][j] == '.')
			{
				a[i - 1][j] = '@';
				count++;
				tmp.push_back(i - 1);
				tmp.push_back(j);
			}

			if (i + 1 < n&&a[i + 1][j] == '.')
			{
				a[i + 1][j] = '@';
				count++;
				tmp.push_back(i + 1);
				tmp.push_back(j);
			}

			if (j - 1 >= 0 && a[i][j - 1] == '.')
			{
				a[i][j - 1] = '@';
				count++;
				tmp.push_back(i);
				tmp.push_back(j - 1);
			}

			if (j + 1 < n&&a[i][j + 1] == '.')
			{
				a[i][j + 1] = '@';
				count++;
				tmp.push_back(i);
				tmp.push_back(j + 1);
			}

		}


	}


	cout << count << endl;
	
	return 0;
}


