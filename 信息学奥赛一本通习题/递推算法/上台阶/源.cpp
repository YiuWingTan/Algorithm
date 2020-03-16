/*
【题目描述】
楼梯有n(71>n>0)阶台阶,上楼时可以一步上1阶,也可以一步上2阶,也可以一步上3阶，编程计算共有多少种不同的走法。

【输入】
输入的每一行包括一组测试数据，即为台阶数n。最后一行为0，表示测试结束。

【输出】
每一行输出对应一行输入的结果，即为走法的数目。

【输入样例】
1
2
3
4
0
【输出样例】
1
2
4
7
*/

#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

long long a[200] = {0,1,2,4};
long long re[200];

int main()
{

	int n,count = 4,j = 0;
	while (cin >> n)
	{
		if (n == 0) break;

		if (n >= count)
		{
			while (count <= n)
			{
				a[count] = a[count-1] + a[count-2] + a[count-3];
				count++;
			}
		}

		re[j++] = a[n];
	}

	for (int i = 0; i < j; i++)
		cout << re[i] << endl;
	return 0;
}
