#include<iostream>
#include<vector>

using namespace std;

char a1[100];
short a[100];
int main()
{
	

	while (cin >> a1)
	{
		int lena = strlen(a1);
		bool isfind = false;
		for (int n = 2; n <= 9; ++n)
		{
			for (int i = 0; i < lena; ++i) a[i] = a1[i] - '0';

			int val = 0,j = 0;
			for (int i = 0; i < lena; i++)
			{
				val = val * 10 + a[i];
				if (val < n) {
					continue;
				}
				val = val%n;
			}

			if (val == 0) {
				cout << n << " ";
				isfind = true;
			}
		}
		
		if (!isfind) cout << "none" << endl;
		else cout << endl;
		memset(a,0,sizeof(a));
	}


	
	return 0;
}


