
/*
����Ŀ������
�Ʋ�����������ָ����������: ���еĵ�һ���͵ڶ�������Ϊ1��������ÿ����������ǰ��2����֮�͡�

����һ��������a��Ҫ��Ʋ����������е�a������1000ȡģ�Ľ���Ƕ��١�

�����롿
��1���ǲ������ݵ�����n���������n�����롣ÿ���������ռ1�У�����һ��������a(1 �� a �� 1000000)��

�������
n�У�ÿ�������Ӧһ�����롣���Ӧ��һ����������Ϊ�Ʋ����������е�a������1000ȡģ�õ��Ľ����

������������
4
5
2
19
1
�����������
5
1
181
1

*/

#include<iostream>
#include<vector>

using namespace std;

short a[1000000];



int main()
{
	vector<int> re;
	int n,m,count = 2;
	a[0] = 0;
	a[1] = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		
		if(count<=m)
			while (count <= m)
			{
				a[count] = (a[count - 1] + a[count - 2])%1000;

				count++;
			}
		re.push_back(a[m]);
	}


	for (int i = 0; i < re.size(); i++)
		cout << re[i]<<endl;

	//system("pause");
	return 0;
}



