
#include<iostream>

using namespace std;

int arr[100000];
int tmp[100000];
long long num = 0;
void merge(int lo,int mid,int hi)
{
	if (lo >= hi) return;

	int i = lo,j = mid+1;
	int k = lo;
	while (k<=hi)
	{
		if (i > mid) tmp[k++] = arr[j++];
		else if (j > hi) tmp[k++] = arr[i++];
		else if (arr[i] < arr[j]) tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}


	for (int i = lo; i <= hi; i++)
		arr[i] = tmp[i];

}



void countInvert(int lo,int hi)
{
	if (lo >= hi) return ;

	int mid = (lo+hi)/2;
	
	countInvert(lo,mid);
	countInvert(mid+1,hi);

	int i = mid;
	int j = hi;
	while (i >= lo)
	{
		while (j > mid&&arr[i] <= arr[j])j--;
		num += j - mid;
		i--;
	}

	merge(lo,mid,hi);

	return ;
}


int main()
{
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	countInvert(0, n - 1);

	cout << num<<endl;

	return 0;
}

