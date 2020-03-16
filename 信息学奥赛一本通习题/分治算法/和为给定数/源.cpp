
#include<iostream>

using namespace std;

int arr[1000000];


void quickSort(int lo,int hi)
{
	if (lo >= hi) return;

	int i = lo + 1,k = lo,j = hi;

	while (i <= j)
	{
		if (arr[k] < arr[i]) swap(arr[i],arr[j--]);
		else if (arr[k] > arr[i]) swap(arr[i++],arr[k++]);
		else i++;
	}

	quickSort(lo,k-1);
	quickSort(j+1,hi);

}

bool bFind(int lo,int hi,int target)
{
	int left = lo, right = hi;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == target) return true;
		else if (arr[mid] > target) right = mid - 1;
		else left = mid + 1;
	}

	return false;
}

int main()
{
	int min = 0;
	int n, target;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> target;

	quickSort(0,n-1);

	for (int i = 0; i <n &&arr[i]<target; i++)
	{
		if (target - arr[i] > arr[i])
		{
			//‘⁄”“±ﬂ—∞’“
			if (bFind(i + 1, n - 1, target - arr[i]))
			{
				min = arr[i];
			}
		}
		else {
			if (bFind(0, i - 1, target - arr[i]))
			{
				min = target - arr[i];
			}
		}
	}

	if (min != 0)
	{
		cout << min << " " << target - min << endl;
	}
	else {
		cout << "No\n";
	}


	return 0;
}


