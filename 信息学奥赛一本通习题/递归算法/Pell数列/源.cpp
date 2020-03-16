
#include<iostream>
using namespace std;


int b[1000001];
int a[1000001] = {0,1,2};


int main()
{
	int n,count = 3;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (; count <= b[i]; count++)
			a[count] = (2 * a[count - 1] + a[count - 2])% 32767;

		cout << a[b[i]]<<endl;

	}


	return 0;
}



