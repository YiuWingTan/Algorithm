
/*

1206：放苹果

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 5276     通过数: 3395
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
*/

#include<iostream>

using namespace std;



int f(int M,int N)
{
	if (M == 0) return 1;
	if (N == 0) return 0;


	if (M < N) return f(M,M);
	return f(M - N, N) + f(M,N-1);

}




int main()
{

	int t,M,N;

	cin >> t;


	for (int i = 0; i < t; i++)
	{
		cin >> M >> N;
		cout << f(M,N)<<endl;
	}


	


	return 0;
}
