
/*

1210：因子分解

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 3521     通过数: 2168
【题目描述】
输入一个数，输出其素因子分解表达式。

【输入】
输入一个整数 n (2≤n<100)。

【输出】
输出该整数的因子分解表达式。

表达式中各个素数从小到大排列。

如果该整数可以分解出因子a的b次方，当b大于1时，写做 a^b ；当b等于1时，则直接写成a。

【输入样例】
60
【输出样例】
2^2*3*5
【来源】

【算法分析】
使用桶排序的思想，设f(n,m)函数的作用是判断n是否能被m整除，m从2开始每找到一个能够整除数组a的对应索引加1，

*/

#include<iostream>
using namespace std;


int a[1000];
int c;
void slove(int n)
{
	if (n == 1) return;

	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{

			a[c++] = i;
			slove(n/i);
			return;
		}
	}

	a[c++] = n;

}


int main()
{
	int n;
	cin >> n;

	slove(n);

	for (int i = 0; i < c; i++)
	{
		int count = 1;

		while (a[i] == a[i + count]) count++;

		if (count + i < c)
		{
			if (count > 1)
			{
				cout << a[i] << "^" << count << "*";
			}
			else cout << a[i]<<"*";
		}
		else
		{
			if (count > 1)
			{
				cout << a[i] << "^" << count;
			}
			else cout << a[i];
		}
		
		i += count - 1;

	}



	return 0;
}


