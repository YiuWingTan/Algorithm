#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(int a,int b)
{
	if (b == 0) return a;
	return gcd(b,a%b);
}

int a[11];
int b[11];

int main()
{
	int denominator = 1, numerator = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		scanf("%d/%d",&a[i],&b[i]);
	}

	for (int i = 0; i < n; i++) denominator *= b[i];
	for (int i = 0; i < n; i++) numerator += denominator/b[i]*a[i];

	int div = gcd(denominator,numerator);

	printf("%d/%d\n",numerator/div,denominator/div);

	return 0;
}
