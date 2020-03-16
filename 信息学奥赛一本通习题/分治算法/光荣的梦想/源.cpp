

#include<iostream>

using namespace std;

int num = 0;
int arr[10000];
int tmp[10000];

void merge(int lo,int mid,int hi)
{
	int i = lo;
	int j = mid + 1;
	int k = lo;

	while (k<=hi)
	{
		if (i > mid) tmp[k++] = arr[j++];
		else if (j > hi) tmp[k++] = arr[i++];
		else if (arr[i] > arr[j]) tmp[k++] = arr[j++];
		else if (arr[i] < arr[j]) tmp[k++] = arr[i++];
		else tmp[k++] = arr[i++];
	}

	for (int i = lo; i <= hi; i++)
	{
		arr[i] = tmp[i];
	}
}

void caluate(int lo,int hi)
{
	if (lo >= hi) return;

	int mid = (hi + lo)/2;

	caluate(lo,mid);
	caluate(mid+1,hi);

	//统计逆序对的数量

	int j = hi;
	int i = mid;

	while (i >= lo)
	{
		while (j > mid&&arr[i] <= arr[j])
		{
			
			j--;
		}
		num += j - mid;
		i--;
	}

	merge(lo,mid,hi);
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];


	caluate(0,n-1);

	cout << num << endl;

	return 0;
}


