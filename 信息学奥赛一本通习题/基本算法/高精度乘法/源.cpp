#include<iostream>
#include<vector>
#include<string>
using namespace std;

char a1[100];
char b1[1001];
short c[2001];
short a[1001];
short b[1001];


int main()
{
	
	


	while (cin >> a1 >> b1)
	{
		
		int lenb = strlen(b1);
		int lena = strlen(a1);
		for (int i = 0; i < lena; i++) a[i] = a1[lena - i-1] - '0';
		for (int i = 0; i < lenb; i++) b[i] = b1[lenb - i-1] - '0';

		
		for (int i = 0; i < lenb; i++)
		{
			int x = 0;
			for (int j = 0; j < lena; j++)
			{
				c[i + j] = c[i + j] + x + (b[i])*a[j];
				x = c[i + j] / 10;
				c[i + j] %= 10;
			}

			c[lena + i] += x;

		}

		int index = lena + lenb - 1;

		while (index >= 0 && c[index] == 0) index--;

		for (int i = index; i >= 0; i--)
		{
				
			cout << c[i];
		}
		cout << endl;
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		memset(c,0,sizeof(c));
	}

	
	return 0;

}



#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


#define LENGTH 1001
int main() {
	
	char a1[LENGTH], b1[LENGTH];
	
	int a[LENGTH], b[LENGTH], c[LENGTH];
	int lena, lenb, lenc, i, j, x;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	
	
	while (cin >> a1 >> b1)
	{
		lena = strlen(a1);
		lenb = strlen(b1);
		
		for (i = 0; i < lena; i++) {
			a[lena - i] = a1[i] - 48;
			
		}
		for (i = 0; i < lenb; i++) {
			b[lenb - i] = b1[i] - 48;
		}

		for (i = 1; i <= lena; i++) {
			x = 0;
			for (j = 1; j <= lenb; j++) {
				
				c[i + j - 1] = a[i] * b[j] + x + c[i + j - 1];
				x = c[i + j - 1] / 10;
				c[i + j - 1] %= 10;
			}
			c[lenb + i] = x;  
		}
		lenc = lena + lenb;
						   
		while (c[lenc] == 0 && lenc > 1) {
			lenc--;
		}
		for (i = lenc; i >= 1; i--) {
			cout << c[i];
		}
	}

	
	return 0;
}



