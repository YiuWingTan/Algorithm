#include<iostream>

using namespace std;

inline int GetPosition(int x)
{
	int e = 1;
	int d = 10;

	for (;;)
	{
		d = x / e;
		if (d < 10) break;
		d >= 100 ? e *= 100 : e *= 10;
	}

	return e;
}

inline bool isPalindrome(int x) {

	if (x < 0) return false;
	if (x < 10) return true;

	int e = GetPosition(x);
	int s = 1;
	while (e >= s)
	{
		
		if (((x / e) % 10) != ((x/s)%10)) return false;
		s *= 10;
		e /= 10;
	}
	return true;
}

int main()
{
	int x;
	cin >> x;

	bool e = isPalindrome(x);
	if (e) cout << "ÊÇ\n";
	else cout << "²»ÊÇ\n";
	getchar();
	getchar();
}