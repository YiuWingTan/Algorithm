/*

1189：Pell数列

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 8891     通过数: 4432
【题目描述】
Pell数列a1,a2,a3,...的定义是这样的，a1=1,a2=2,...,an=2an−1+an−2(n>2)。

给出一个正整数k，要求Pell数列的第k项模上32767是多少。

【输入】
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数k (1≤k<1000000)。

【输出】
n行，每行输出对应一个输入。输出应是一个非负整数。

【输入样例】
2
1
8
【输出样例】
1
408

*/


#include<iostream>
#include<vector>
using namespace std;

int a[1000000];

int main()
{
	int n,count = 3;
	vector<int> re;
	a[1] = 1; a[2] = 2;
	int b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
	
		cin >> b;

		if (b >= count)
		{
			while (count <= b)
			{
				a[count] = (2 * a[count - 1] + a[count - 2])% 32767;
				count++;
			}
		}
		re.push_back(a[b]);
	}

	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i]<<endl;
	}
	//system("pause");
	return 0;
}


