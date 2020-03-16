



#include<iostream>

using namespace std;


int n;
int num, mincount = 2147483647;
int a[11];
int b[11];
int tmp[10][10];

int gcd(int a,int b)
{
	if (b == 0) return a;

	return gcd(b,a%b);
}


void place(int k)
{
	if (k == n) {

		if (num < mincount) mincount = num;
		return;
	}


	for (int i = 1; i <= num; i++)
	{
		bool isok = true;
		for (int j = 0; j < n; j++)
		{
			if (b[j] != i) continue;
			//�ҵ�һ�����Ԫ����
				
			if (tmp[k][j] == 0) tmp[k][j] = tmp[j][k] = gcd(a[k],a[j]);

			if (tmp[k][j] != 1)
			{
				isok = false;
				break;
			}
		}

		//���Լ��뵽��i����
		if (isok)
		{
			b[k] = i;
			place(k+1);
			b[k] = 0;
		}

	}

	//�������κ�һ��,�Լ�������
	b[k] = ++num;
	place(k+1);
	b[k] = 0;
	num--;
}

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	place(0);

	cout << mincount << endl;

	return 0;
}

