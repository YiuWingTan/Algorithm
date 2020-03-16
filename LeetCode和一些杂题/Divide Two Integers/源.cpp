/*
	难度 中等 主题 数学 ，二分查找
*/
/*
评价 ：要死
*/
#include<vector>
#include<iostream>
using namespace std;

const int half = INT_MAX >> 1;

int judge(int dividend,int divisor,int num)
{
	if (dividend < 0 && divisor>0) num *= -1;
	if (dividend > 0 && divisor<0) num *= -1;

	return num;
}

int divide(int dividend, int divisor) {

	int offset = 0;
	if (divisor == 1 && dividend == INT_MIN) return INT_MIN;
	if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
	if (divisor == INT_MIN&&dividend == INT_MAX) return 0;
	if (dividend == INT_MIN) { dividend = -INT_MAX; offset = 1; }
	if (divisor == INT_MIN) { divisor = -INT_MAX; offset = 1; }

	int dd =abs(dividend);
	int dr =abs(divisor);
	
	int num = 0;
	if (dd == dr) return judge(dividend, divisor,1);
	if (dr == 1) return judge(dividend, divisor, dd);
	
	while (dd > dr&&dr!=1)
	{
		int n = 0;
		
		while (dr <= half&&((dr << n)) < dd)
		{
			n++;
			if (dr << n >= half) break;
			
		}
		if (n <= 0) n = 1;
		num += (1 << n - 1);
		dd -= dr << n - 1;
	}
	if (dd+offset == dr) 
		num++;
	
	return judge(dividend,divisor,num);
}

int main()
{
	int dd = INT_MIN;
	int dr = 2;

	int n = divide(dd,dr);
	printf("%d /  %d = %d",dd,dr,n);
	
	getchar();
	return 0;
}