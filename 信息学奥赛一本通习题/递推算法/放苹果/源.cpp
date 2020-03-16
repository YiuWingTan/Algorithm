/*
【题目描述】
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。

【输入】
第一行是测试数据的数目t（0≤t≤20）。以下每行均包含二个整数M和N，以空格分开。1≤M，N≤10。

【输出】
对输入的每组数据M和N，用一行输出相应的K。

【输入样例】
1
7 3
【输出样例】
8

【算法分析】
	

*/




#include<iostream>
using namespace std;

//放苹果函数
int f(int m, int n)
{
	//当盘子的数量比苹果的数量多的时候
	if (m < n)
		return f(m,m);

	//边界条件 当苹果数量为0的时候只有1种 放法
	if (m == 0) return 1;

	//边界条件 当盘子的数量为0的时候只有 0种放法
	if (n == 0) return 0;


	//当苹果的数量比盘子的数量多的时候
	return f(m,n-1) + f(m- n,n);

}

int a[20];

int main()
{

	int n,count = 0;
	cin >> n;

	while (n-- > 0)
	{
		int m, n;
		cin >> m >> n;

		a[count++] = f(m,n);
	}

	for (int i = 0; i < count; i++)
		cout << a[i]<<endl;

	return 0;
}



