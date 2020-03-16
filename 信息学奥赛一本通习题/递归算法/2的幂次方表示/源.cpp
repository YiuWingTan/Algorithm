
#include<iostream>

using namespace std;

const unsigned int mask = 0x80000000;

/*
并不是最好的递归
*/
void f(unsigned int n)
{
	if (n == 0) {
		cout << "0";
		return;
	}
	bool first = true;

	for (int i = 31; i >= 0; i--)
	{
		if (n&mask) {
		
			if (first)
			{
				if (i != 1)
				{
					cout << "2("; f(i); cout << ")";
				}
				else cout << "2";
				first = false;
			}
			else {
				if (i != 1)
				{
					cout << "+2("; f(i); cout << ")";
				}
				else cout << "+2";
			}
		}
		n = n << 1;
	}


}


/*
一个更好的递归
*/
void calculate(int n, int step)
{
	if (n == 0)
		return;
	calculate(n / 2, step + 1);
	if (n % 2)
	{
		if (n / 2)
			cout << "+";
		if (step == 1)
			cout << "2";
		else
		{
			cout << "2(";
			if (step == 0)
				cout << "0";
			else
				calculate(step, 0);
			cout << ")";
		}
	}
}

int main()
{
	unsigned int n;
	cin >> n;
	f(n);
	cout << endl;
	return 0;
}


