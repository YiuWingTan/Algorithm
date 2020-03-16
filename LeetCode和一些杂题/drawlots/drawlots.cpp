#include<iostream>
using namespace std;

inline void exchange(int *a,int i,int j)
{
	int middle = a[i];
	a[i] = a[j];
	a[j] = middle;
}

//三向切分快速排序
inline void quickSort_3(int *a,int lo,int hi)
{
	if (lo >= hi) return;

	int n = lo;
	int max = hi;
	int min = lo+1;
	int v = a[lo];

	while (min <= max)
	{
		if (v < a[min]) exchange(a,min,max--);
		else if (v > a[min]) exchange(a,n++,min++);
		else min++;
	}
	
	quickSort_3(a,lo,n);
	quickSort_3(a,n+1,hi);
}

//二分查找
inline int binarySearch(int *a,int lo,int hi,int target)
{

	if (a[lo] == target) return lo;

	if (lo == hi) return -1;

	int m = (hi - lo) / 2+lo;

	if (a[m] > target) return binarySearch(a,lo,m,target);
	else if(a[m]<target) return binarySearch(a,m+1,hi,target);
	else m;
}

int main()
{
	bool isfind = false;
	int n,m;
	cin >> n;
	cin >> m;
	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quickSort_3(a,0,n-1);
	/*for (int i = 0; i < n; i++)
	{
		cout << k[i]<<"  ";
	}
	cout << endl;*/


	for (int i = 0; i < n&&!isfind; i++)
	{
		for (int j = 0; j < n && !isfind; j++)
		{
			for (int k = 0; k < n && !isfind; k++)
			{
				int num = binarySearch(a,0,n-1,(m - a[i] - a[j] - a[k]));

				if (num != -1) {
					cout << "Yes，值为:" << a[i] << "+" << a[j] << "+" << a[k] << "+" << a[num] << " = " << m << endl;

					isfind = true;
				}
			}
		}
	}

	system("pause");

	getchar();

    return 0;
}

