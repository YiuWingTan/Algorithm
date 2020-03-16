
#include<iostream>

using namespace std;

int a[1000][2];

inline int comp(int i,int j)
{
	return a[i][1] == a[j][1] ? a[i][0] - a[j][0] : a[i][1] - a[j][1];
}

inline void change(int i,int j)
{
	std::swap(a[i][0],a[j][0]);
	std::swap(a[i][1],a[j][1]);
}

void quickSort(int lo,int hi)
{

	if (lo >= hi) return;

	int i = lo + 1, k = lo, j = hi;

	while (i <= j)
	{
		int cmp = comp(i,k);
		if (cmp < 0)
		{
			change(i++,k++);
		}
		else if (cmp > 0)
		{
			change(i,j--);
		}
		else
		{
			i++;
		}

	}

	 quickSort(lo,k-1);
	 quickSort(j+1,hi);

}


int main()
{

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0]>>a[i][1];
	}


	quickSort(0,n-1);


	int num = 1;
	int start = a[0][1];

	for (int i = 0; i < n; i++)
	{
		if (a[i][0] >= start)
		{
			start = a[i][1];
			num++;
		}
	}

	cout << num << endl;

	return 0;
}





