
#include<iostream>
#include<cstdio>
using namespace std;

int n;
int a[1000];
int b[1000];

void swap(int i,int j)
{
	
}

void quickSort(int lo,int hi)
{

	if (lo >= hi) return;

	int i = lo + 1;
	int k = lo;
	int j = hi;

	while (i <= j)
	{
		if (a[k] > a[i]) {
			std::swap(a[i], a[k]);
			std::swap(b[i++],b[k++]);
		}
		else if (a[k] < a[i]) {
			std::swap(a[i], a[j]);
			std::swap(b[i],b[j--]);
		}
		else i++;
	}


	quickSort(lo,k-1);
	quickSort(j+1,hi);
}


int main()
{
	cin >> n;

	float waitTime = 0.0f;
	float totalTime = 0.0f;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i]= i;
	}

	quickSort(0,n-1);

	for (int i = 0; i < n; i++)
	{
		cout << b[i]+1 << " ";
		if (i-1 >= 0)
			waitTime += a[i-1];
		totalTime += waitTime;
	}


	printf("\n%0.2f",totalTime/n);

	

	


	return 0;
}





