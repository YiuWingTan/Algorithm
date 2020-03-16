#include<iostream>
#include<vector>

using namespace std;

vector<int> auk;

void Merge(vector<int> &arr,int lo,int mid,int hi)
{
	for (int i = lo; i <= hi; i++)
		auk[i] = arr[i];

	int i = lo, j = mid + 1,k = lo;

	while (i <= mid || j <= hi)
	{
		if (i > mid) arr[k++] = auk[j++];
		else if (j > hi) arr[k++] = auk[i++];
		else if (auk[i] > auk[j]) arr[k++] = auk[j++];
		else arr[k++] = auk[i++];
	}

}

//递归版本
void dSort(vector<int> &arr,int lo,int hi)
{
	if (lo >= hi) return;

	int mid = lo + (hi - lo) / 2;
	dSort(arr,lo,mid);
	dSort(arr,mid+1,hi);
	Merge(arr,lo,mid,hi);
}

int min(int i,int j)
{
	return i > j ? j : i;
}

//非递归版本
void dSort(vector<int> &arr)
{
	int k = 1;
	int lo = 0;
	int mid = 0;
	int hi = 0;
	int len = arr.size();
	while (k < arr.size())
	{
		lo = 0;
		while(lo<len)
		{
			hi = min(lo + k * 2 - 1, arr.size() - 1);
			mid = lo + (hi - lo) / 2;
			Merge(arr,lo,mid,hi);
			if (len - hi + 2 < k * 2)
			{
				Merge(arr, lo, hi, len - 1);
				hi = len - 1;
			}
			lo = hi + 1;
		}

		k *= 2;
	}
}


//归并排序2-循环实现方法
void dSort2(vector<int> &arr)
{
	if (arr.size() == 0) return;

	int len = arr.size();
	int n = 1;
	int lo,mid,hi;
	lo = mid = hi = 0;


	while (n < len)
	{
		lo = hi = mid = 0;
		while (hi < len-1)
		{
			mid = lo + n - 1;
			hi = min(lo+2*n-1,len-1);
			Merge(arr,lo,mid,hi);
			if ((len - hi - 1) < n * 2)
			{
				Merge(arr,lo,hi,len-1);
				break;
			}
			lo = hi + 1;
		}
		n *= 2;
	}
}


int main()
{
	vector<int> arr = { 54,2,3,66,3,2,5,414,5,5,1,85,8,5,-8,6,-4,-88,-3,0 };
	auk.resize(arr.size());

	dSort2(arr);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	getchar();
	return 0;
}
