/*
����Ŀ������
¥����n(71>n>0)��̨��,��¥ʱ����һ����1��,Ҳ����һ����2��,Ҳ����һ����3�ף���̼��㹲�ж����ֲ�ͬ���߷���

�����롿
�����ÿһ�а���һ��������ݣ���Ϊ̨����n�����һ��Ϊ0����ʾ���Խ�����

�������
ÿһ�������Ӧһ������Ľ������Ϊ�߷�����Ŀ��

������������
1
2
3
4
0
�����������
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
