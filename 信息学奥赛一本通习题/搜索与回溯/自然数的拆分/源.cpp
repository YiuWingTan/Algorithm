

#include<iostream>
#include<cstdio>
using namespace std;

int a[1000];

void print(int k)
{
	printf("%d=%d",a[0],a[1]);

	for (int i = 2; i <k; i++)
	{
		printf("+%d",a[i]);
	}
	cout << endl;

}

void search(int n,int r,int s) {

	if (n == 0) {
		print(r);
		return;
	}

	for (int i = s; i <=n; i++)
	{
		a[r] = i;
		search(n-i,r+1,i);
	}

}



int main()
{

	int n;
	cin >> n;
	a[0] = n;
	for (int i = 1; i < n; i++)
	{
		a[1] = i;
		search(n-i,2,i);
	}


	return 0;
}



