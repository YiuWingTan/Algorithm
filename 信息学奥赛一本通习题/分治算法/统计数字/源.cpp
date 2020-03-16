

#include<iostream>
using namespace std;

int arr[200001];


void kkkk(int lo,int hi)
{
	if (lo >= hi) return;

	int i = lo + 1;;
	int j = hi;
	int k = lo;

	while (i <= j)
	{
		if (arr[i] < arr[k]) swap(arr[i++],arr[k++]);
		else if (arr[i] > arr[k]) swap(arr[i],arr[j--]);
		else i++;
	}

	kkkk(lo, k-1);
	kkkk(j + 1, hi);

	return;
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	kkkk(0,n-1);

	int i = 0;
	int j = 0;

	while (i < n)
	{
		while (j + 1 < n&&arr[j] == arr[j + 1]) j++;

		cout << arr[i] << " " << (j - i+1)<<endl;

		i = j + 1;
		j = i;
	}




	return 0;
}

