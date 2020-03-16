
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;


struct Point
{
	int x, y;
} points[100];




int cmp(int i,int j)
{
	if (points[i].y == points[j].y) return points[i].x - points[j].x;

	return points[i].y - points[j].y;

}


void qSort(int lo,int hi)
{
	if (lo >= hi) return;

	int i = lo + 1;
	int k = lo;
	int j = hi;

	while (i <=j )
	{
		int val = cmp(i,k);

		if (val > 0)
		{
			swap(points[i],points[j]);
			j--;
		}
		else if (val < 0)
		{
			swap(points[i],points[k]);
			i++; k++;
		}
		else
		{
			i++;
		}

	}

	qSort(lo,k-1);
	qSort(j+1,hi);

}


int main()
{
	vector<Point> re;
	int n;
	cin >> n;



	for (int i = 0; i < n; i++)
	{
		cin >> points[i].x >> points[i].y;
	}

	qSort(0,n-1);

	
	int maxIndex = n-1;
	
	re.push_back(points[maxIndex]);

	for (int i = n - 1; i >= 0; i--)
	{

		if (points[maxIndex].x < points[i].x)
		{
			re.push_back(points[i]);
			maxIndex = i;
		}

	}

	for (int i = 0; i < re.size(); i++)
	{

		if (i != re.size() - 1)
		{
			printf("(%d,%d),",re[i].x,re[i].y);
		}
		else
		{
			printf("(%d,%d)\n", re[i].x, re[i].y);
		}

	}
	return 0;
}



