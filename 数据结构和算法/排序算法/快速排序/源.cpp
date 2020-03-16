#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>&arr,int i,int j)
{
	int mid = arr[i];
	arr[i] = arr[j];
	arr[j] = mid;
}

//交换切分函数
int partion_swap(vector<int>&arr,int lo,int hi)
{
	int k = lo;
	int i = lo + 1;
	int j = hi;

	while (i < j)
	{
		while (i < j&&arr[i] <= arr[k]) i++;
		while (j > i&&arr[j] > arr[k]) j--;

		if (i < j) swap(arr,i,j);
	}

	swap(arr,k,i-1);

	return i-1;
}

int partion_3way(vector<int>&arr, int lo, int hi)
{
	if (lo >= hi) return lo;

	int k = lo;
	int i = lo + 1;
	int j = hi;

	while (i <= j)
	{
		if (arr[k] < arr[i]) swap(arr, i, j--);
		else if (arr[k] > arr[i]) swap(arr, k++, i++);
		else i++;
	}
	return 1;
}

int partion_dig(vector<int>&arr, int lo, int hi)
{
	if (lo >= hi) return lo;

	int k = arr[lo];
	int i = lo + 1;
	int j = hi;
	int dig = lo;;

	while (i<j)
	{
		while (j > i&&arr[j] >= k)j--;
		if (i >= j) break;
		arr[dig] = arr[j];
		dig = j;
		while (i < j&&arr[i] < k)i++;
		if (i >= j) break;
		arr[dig] = arr[i];
		dig = i;
	}

	
	if (i == lo + 1 && arr[i] > arr[lo + 1]) swap(arr,i,lo+1);
	else {
		arr[i] = k;
	}

	return i;
}

//递归实现
void qSort(vector<int>&arr,int lo,int hi)
{
	if (lo >= hi) return;

	int k = lo;
	int i = lo + 1;
	int j = hi;

	while (i <= j)
	{
		if (arr[k] < arr[i]) swap(arr, i, j--);
		else if (arr[k] > arr[i]) swap(arr, k++, i++);
		else i++;
	}

	qSort(arr,lo,k-1);
	qSort(arr,i,hi);
}

//循环实现
void qSort2(vector<int>&arr,int lo,int hi)
{
	if (lo >= hi) return;

	int mid = partion_dig(arr,lo,hi);

	qSort2(arr,lo,mid-1);
	qSort2(arr,mid+1,hi);
}

int main()
{
	vector<int> arr = {  };

	qSort2(arr,0,arr.size()-1);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<int> arr2 = { 54,2,3,66,3,2,5,414,5,5,1,85,8,5,-8,6,-4,-88,-3,0 };

	qSort(arr2,0,arr2.size()-1);

	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	getchar();
	return 0;
}