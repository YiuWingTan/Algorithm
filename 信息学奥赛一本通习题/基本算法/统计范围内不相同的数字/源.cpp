#include<iostream>
#include<vector>

using namespace std;

int countNumbersWithUniqueDigits(int n) {


	if (n == 1) return 10;
	if (n == 0) return 1;


	int tmp  = 9;
	int sum = 10;
	int count = 1;

	for (int i = 1; i < n&&i<10; i++)
	{
		tmp *= 10 - count++;
		sum += tmp;
	}
	return sum;
}

int main()
{


	getchar();
	return 0;
}


