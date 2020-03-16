
#include<iostream>
#include<algorithm>

using namespace std;

int arr[100000];


int partion_find(int lo,int hi,int target)
{
	if (lo >= hi) return lo;
	int i = lo+1;
	int k = lo;
	int j = hi;


	while (i <= j)
	{
		if (arr[i] < arr[k]) swap(arr[i++],arr[k++]);
		else if (arr[i] > arr[k]) swap(arr[i],arr[j--]);
		else i++;
	}

	if (target > k) return partion_find(k+1,hi,target);
	else if (target < k) return partion_find(lo,k-1,target);
	return target;
}

void nuoDong(int a[], int s, int e, int k) {
	if (s >= e)
		return;
	int t = a[s];
	int i = s, j = e;
	while (i != j) {
		while (i < j&&t <= a[j]) j--;
		swap(a[j], a[i]);
		while (i < j&&t >= a[i]) i++;
		swap(a[j], a[i]);
	}
	int num = e - i + 1;
	if (num == k) return;
	if (num > k) nuoDong(a, i + 1, e, k);
	if (num < k) nuoDong(a, s, i - 1, k - num);
}
void quickSort(int lo,int hi)
{
	if (lo >= hi) return;

	int i = lo + 1;
	int k = lo;
	int j = hi;


	while (i <= j)
	{
		if (arr[i] < arr[k]) swap(arr[i++], arr[k++]);
		else if (arr[i] > arr[k]) swap(arr[i], arr[j--]);
		else i++;
	}

	quickSort(lo,k-1);
	quickSort(j+1,hi);
}


int main()
{
	int n, k;

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> k;

	
	nuoDong(arr, 0,n - 1,k);
		sort(arr + n - k, arr + n);
	
	for (int i = n - 1; i >= n - k; i--)
		cout << arr[i]<<endl;


	return 0;
}

