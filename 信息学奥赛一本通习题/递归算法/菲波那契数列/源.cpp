/*

【题目描述】
菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。

给出一个正整数a，要求菲波那契数列中第a个数是多少。

【输入】
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1≤a≤20)。

【输出】
输出有n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数的大小。

【输入样例】
4
5
2
19
1
【输出样例】
5
1
4181
1


*/

#include<iostream>

using namespace std;
int a[100000];

int main()
{

	int dp[21] = {0,1};
	int count = 2;
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{

		for (count; count <= a[i]; count++)
		{
			dp[count] = dp[count-1] + dp[count-2];
		}

		cout << dp[a[i]]<<endl;


	}


	return 0;
}

