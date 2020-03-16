#include<iostream>
#include<string>

using namespace std;


char a1[300];
int a[300];
int b[300];

bool isFind(int a[],int len)
{
	int i = 0,j = len-1;
	//if (len == 1) return false;
	while (i < j) {
		if (a[i] != a[j]) return false;
		i++; j--;
	}
	return true;
}


int main()
{
	int m;
	
	while (cin >> m >> a1)
	{
		
		int count = 0;
		int lena = strlen(a1);
		for (int i = 0; i < lena; i++) a[i] = a1[i] - '0';

		while (count < 30 && !isFind(a, lena))
		{
			//加a中的内容反向复制到b中
			int j = 0;
			for (int i = lena - 1; i >= 0; i--) b[j++] = a[i];
			//进行加法
			int x = 0;
			for (int i = 0; i < lena; i++)
			{
				
				a[i] = (a[i] + b[i]+x);
				x = a[i]/ m;
				a[i] %= m;
			}
			if (x != 0) a[lena++] = x;
			count++;
		}


		if (count < 30) {
			//for (int i = 0; i < lena; i++) cout << a[i];
			//cout << endl;
			cout << count<<endl;
		}
		else {
			cout << "Impossible"<<endl;
		}
		memset(a,0,300);
		memset(b,0,300);

	}
	return 0;
}

