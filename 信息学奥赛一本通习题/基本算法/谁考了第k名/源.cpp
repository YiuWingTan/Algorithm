#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
using namespace std;


struct student
{
	double grade;
	char id[20];
};

student students[101];


inline void change(int lo,int hi)
{
	student tmp =  students[lo];
	students[lo] = students[hi];
	students[hi] = tmp;
}

int slice(int lo,int hi)
{
	int k = lo;
	int i = lo + 1, j = hi;

	while (i <= j)
	{
		if (students[i].grade < students[k].grade)change(i++,k++);
		else if (students[i].grade >students[k].grade) change(i,j--);
		else i++;
	}
	return j;
}


int main()
{

	int n, k;

	while (cin >> n >> k)
	{

		for (int i = 0; i < n; i++)
		{
			cin >> students[i].id>> students[i].grade;
		}

		int lo = 0, hi = n-1;
		int mid;
		k--;
		while (lo <= hi)
		{
			mid = slice(lo,hi);

			if (mid <k) {
				lo = mid + 1;
				
			}
			else if(mid>k)
			{
				hi = mid - 1;
			}
			else break;
		}

		printf("%s %g\n", students[k].id, students[k].grade);


	}
	return 0;
}



