

/*
1224：最大子矩阵

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 2571     通过数: 1682
【题目描述】
已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1×1)子矩阵。

比如，如下4×4的矩阵

09−4−1−2218−7−6−40021−2
的最大子矩阵是

9−4−1218
这个子矩阵的大小是15。

【输入】
输入是一个N×N的矩阵。输入的第一行给出N(0<N≤100)。再后面的若干行中，依次(首先从左到右给出第一行的N个整数，再从左到右给出第二行的N个整数……)给出矩阵中的N2个整数，整数之间由空白字符分隔(空格或者空行)。已知矩阵中整数的范围都在[−127,127]。

【输出】
输出最大子矩阵的大小。

【输入样例】
 4
 0 -2 -7  0
 9  2 -6  2
-4  1 -4  1
-1  8  0 -2
【输出样例】
15

*/

#include<iostream>

using namespace std;


int mm[100][100];
int tmp[100];


int main()
{
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> mm[i][j];
	}

	int max = -10000;
	int tmp_b = 0;
	for (int i = 0; i < n; i++)
	{
		memset(tmp,0,sizeof(tmp));

		for (int k = i; k < n; k++)
		{
			tmp_b = 0;
			for (int j = 0; j < n; j++)
			{
				tmp[j] += mm[k][j];

				if (tmp_b < 0)
					tmp_b = tmp[j];
				else tmp_b += tmp[j];

				if (tmp_b > max) max = tmp_b;

			}


		}

	}


	cout << max << endl;

	return 0;

}

