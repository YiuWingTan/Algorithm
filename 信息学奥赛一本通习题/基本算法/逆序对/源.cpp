#include<iostream>
#include<vector>

using namespace std;

int a[100100];
long long _count;
int tmp[100100];

inline int min(int i,int j)
{
	return i > j ? j : i;
}

void merge(int lo, int mid,int hi)
{
	int i = lo;
	int j = mid + 1;
	int k = lo;

	while (i <= mid || j <= hi)
	{
		if (i > mid) tmp[k++] = a[j++];
		else if (j > hi) tmp[k++] = a[i++];
		else if (a[i] > a[j]) tmp[k++] = a[j++];
		else tmp[k++] = a[i++];
	}

	//拷贝会原来的数组


	for (int i = lo; i <= hi; i++)
		a[i] = tmp[i];


}

void mergeSort(int lo,int hi)
{
	if (lo >= hi) return;

	int mid = lo + (hi - lo)/2;

	mergeSort(lo,mid);
	mergeSort(mid+1,hi);

	int j = hi;
	for (int i = mid; i >= lo; --i)
	{

		while (j>mid&&a[i] <= a[j])j--;
		_count += j - mid;
	}

	merge(lo,mid,hi);

	

}

int main()
{

	int n;

	while (cin >> n)
	{
		for (int i = 0; i < n; i++) cin >> a[i];

		_count = 0;

		mergeSort(0,n-1);

		cout << _count<<endl;

		

	}


	return 0;
}


