
#include<iostream>
using namespace std;

int arr[100000];
int targets[100000];

int abs(int a)
{
	return a > 0 ? a : -a;
}

void quickSort(int lo, int hi)
{
	if (lo >= hi) return;

	int i = lo + 1;;
	int j = hi;
	int k = lo;

	while (i <= j)
	{
		if (arr[i] < arr[k]) swap(arr[i++], arr[k++]);
		else if (arr[i] > arr[k]) swap(arr[i], arr[j--]);
		else i++;
	}

	quickSort(lo, k - 1);
	quickSort(j + 1, hi);

	return;
}


int find(int lo,int hi,int target)
{
	
	if (arr[lo] >= target)return arr[lo];
	if (arr[hi] <= target) return arr[hi];

	int left = lo;
	int right = hi;


	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == target) return target;
		if (arr[mid] <=target)
		{
			left = mid + 1;
		}
		else right = mid - 1;

	}

	if (abs(target - arr[right]) <= abs(target - arr[left]))
		return arr[right];
	else return arr[left];
}


int main()
{

	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++) cin>>arr[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> targets[i];

	//quickSort(0,n-1);

	for (int i = 0; i < m; i++)
	{
		int re = find(0,n-1,targets[i]);
		cout << re<<endl;
	}


	return 0;
}

