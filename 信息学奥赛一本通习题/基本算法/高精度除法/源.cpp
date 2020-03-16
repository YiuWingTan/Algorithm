#include<iostream>
#include<algorithm>
using namespace std;

char a1[300];
char d1[300];

short c[300];
short a[300];
short d[300];

//单精度除法
void singleFloatCaulate()
{
	int b = 0, lena, x = 0, lenc = 0;
	while (cin >> a1 >> b)
	{
		if (b == 0) {
			//printf("发生除零错误\n");
			continue;
		}
		lena = strlen(a1);
		x = 0;
		for (int i = 0; i < lena; i++) a[i] = a1[i] - '0';

		for (int i = 0; i < lena; i++)
		{
			c[i] = (x * 10 + a[i]) / b;
			x = (x * 10 + a[i]) % b;
		}
		lenc = 0;
		while (lenc < lena&&c[lenc] == 0) lenc++;

		for (int i = lenc; i < lena; i++) cout << c[i];
		cout << endl;
	}


}

int compare(int head, int tail,int lend) {

	if ((tail - head + 1) > lend) return 1;
	if (head > tail) return -1;
	int j = 0;
	for (int i = head; i <= tail; i++)
	{
		if (a[i] > d[j]) return 1;
		else if (a[i] < d[j]) return -1;
		++j;
	}
	return 0;
}


//高精度除法
void doubleFloatCaulate()
{
	int lena,lend,lenc,k = 0;

	while (cin >> a1 >> d1)
	{
		lena = strlen(a1);
		lend = strlen(d1);
		for (int i = 0; i < lena; i++) a[i] = a1[i] - '0';
		for (int i = 0; i < lend; i++) d[i] = d1[i] - '0';
		k = 0;
		int head = 0, tail = lend-1;
		int count = 0;
		while (compare(head, lena-1, lend) >= 0) {

			if (compare(head, tail, lend) < 0) ++tail;

			//进行减法
			
			while (compare(head, tail, lend)>=0)
			{
				int j = 0;
				for (int i = lend - 1; i >= 0; i--)
				{
					if (a[tail - j] < d[i]) {
						a[tail - j - 1]--;
						a[tail - j] += 10;
					}

					a[tail - j] -= d[i];
					j++;

				}
				count++;
				if (a[head] == 0) head++;
			}
			c[k++] = count;
			count = 0;
			head = tail + 1;
			tail = min(head + (lend - 1),lena-1);
		}
		while (head < lena&&a[head] == 0) {
			c[k++] = 0;
			head++;
		}
		
		for (int i = 0; i <k; i++) cout << c[i]; cout << endl;
		
		int i = 0;
		while (i < lena&&a[i] == 0) ++i;
		for (i; i < lena; i++) cout << a[i]; cout << endl;
		memset(c,0,sizeof(c));
	}

}

int main()
{
	
	doubleFloatCaulate();


	
	return 0;
}



