/*
����Ŀ������
��һ���׸���Ⱥס������״���������ڣ�������Ϊn*n�ľ���ÿ�����Ϊһ�����䣬���������ס�ˣ�Ҳ���ܿ��š��ڵ�һ�죬��Щ��������˵������У��Ժ�ÿ�죬�����е��˻�ʹ���ھӴ�Ⱦ�����У����Ѿ��ò��Ĳ��䣩���շ��䲻�ᴫȾ���������m������е�������

�����롿
��һ��һ������n��n������100����ʾ��n*n�����᷿�䡣

��������n�У�ÿ��n���ַ�����.����ʾ��һ��÷���ס�Ž������ˣ���#����ʾ�÷�����ţ���@����ʾ��һ��÷���ס�ŵ����е��ˡ�

��������һ����һ������m��m������100��

�������
�����m�죬�����е�������

������������
5
....#
.#.@.
.#@..
#....
.....
4
�����������
16

*/


#include<iostream>
#include<vector>
using namespace std;

char a[100][100];

int main()
{

	int n,m,count = 0;
	vector<int> tmp;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>a[i][j];
			if (a[i][j] == '@') {
				count++;
				tmp.push_back(i);
				tmp.push_back(j);
			}
		}
	}

	cin >> m;

	
	for (int k = 1; k < m; k++)
	{
		int num = tmp.size();
		for (int c = 0; c < num; c+=2)
		{
			int i = tmp[c]; int j = tmp[c + 1];

			if (i - 1 >= 0 && a[i - 1][j] == '.')
			{
				a[i - 1][j] = '@';
				count++;
				tmp.push_back(i - 1);
				tmp.push_back(j);
			}

			if (i + 1 < n&&a[i + 1][j] == '.')
			{
				a[i + 1][j] = '@';
				count++;
				tmp.push_back(i + 1);
				tmp.push_back(j);
			}

			if (j - 1 >= 0 && a[i][j - 1] == '.')
			{
				a[i][j - 1] = '@';
				count++;
				tmp.push_back(i);
				tmp.push_back(j - 1);
			}

			if (j + 1 < n&&a[i][j + 1] == '.')
			{
				a[i][j + 1] = '@';
				count++;
				tmp.push_back(i);
				tmp.push_back(j + 1);
			}

		}


	}


	cout << count << endl;
	
	return 0;
}


