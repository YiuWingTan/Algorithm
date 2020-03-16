#include<iostream>
using namespace std;

bool trees[1024*1024+1];
#define Len 1024*10241+1

int getLen(int n)
{
	int len = 1;
	for (int i = 0; i < n; i++) len *= 2;
	
	return len - 1;
}

int main()
{
	int D, I;
	cin >> D >> I;

	int number;
	int n = 1;
	int len = getLen(D);

	while (I > 0)
	{
		n = 1;
		while (2 * n <= len)
		{
			if (trees[n])
			{
				trees[n] = false;
				n = n * 2 + 1;
				
			}
			else
			{
				trees[n] = true;
				n = n * 2;
			}

		}


		I--;
	}

	cout << n << endl;

	return 0;
}

