
/*

1210�����ӷֽ�

ʱ������: 1000 ms         �ڴ�����: 65536 KB
�ύ��: 3521     ͨ����: 2168
����Ŀ������
����һ����������������ӷֽ���ʽ��

�����롿
����һ������ n (2��n<100)��

�������
��������������ӷֽ���ʽ��

���ʽ�и���������С�������С�

������������Էֽ������a��b�η�����b����1ʱ��д�� a^b ����b����1ʱ����ֱ��д��a��

������������
60
�����������
2^2*3*5
����Դ��

���㷨������
ʹ��Ͱ�����˼�룬��f(n,m)�������������ж�n�Ƿ��ܱ�m������m��2��ʼÿ�ҵ�һ���ܹ���������a�Ķ�Ӧ������1��

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


