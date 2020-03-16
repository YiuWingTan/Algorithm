#include<iostream>

using namespace std;

int reverse(int x)
{
	int rev = 0;
	int pop =0;
	while (x != 0)
	{
		int pop = x % 10;
		x /= 10;

		//ÅĞ¶ÏÊÇ·ñÔ½½ç
		if (rev > INT_MAX / 10 || (rev == INT_MAX/10)&&pop>7) return 0;
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10) && pop < -8) return 0;

		rev = rev * 10 + pop;

	}

	return rev;
}

int main()
{
	int n = (int)(0 - (1LL << 31));

	cout << n<<endl;

	getchar();
}