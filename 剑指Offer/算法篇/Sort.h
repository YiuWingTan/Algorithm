#pragma once
#include<iostream>
#include<vector>
using namespace std;
/***********/
//—°‘Ò≈≈–Ú
void SelectSort(vector<int>  arr)
{
	printf("—°‘Ò≈≈–Ú\n");
	if (arr.size() < 0) return;


	for (int i = 0; i < arr.size(); i++)
	{
		int min = i;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		int mid = arr[min];
		arr[min] = arr[i];
		arr[i] = mid;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
//√∞≈›≈≈–Ú
void MaoPaoSort(vector<int> arr)
{
	printf("√∞≈›≈≈–Ú\n");
	if (arr.size() < 0) return;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 1; j < arr.size() - i; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				int mid = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = mid;
			}
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
//≤Â»Î≈≈–Ú
void InsertSort(vector<int> arr)
{
	printf("≤Â»Î≈≈–Ú\n");
	if (arr.size() < 0) return;

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i; j >= 1 && arr[j - 1] > arr[j]; j--)
		{
			int mid = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = mid;
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
int max(int v, int u)
{
	return v > u ? v : u;
}
int min(int v, int u)
{
	return v > u ? u : v;
}

void bing(vector<int> &arr, int lo, int mid, int hi)
{
	vector<int> m;
	int i = lo;
	int j = mid + 1;
	while (m.size() != (hi - lo + 1))
	{
		if (i > mid) m.push_back(arr[j++]);
		else if (j > hi) m.push_back(arr[i++]);
		else if (arr[i] > arr[j]) m.push_back(arr[j++]);
		else m.push_back(arr[i++]);
	}

	for (int i = lo; i <= hi; i++)
	{
		arr[i] = m[i - lo];
	}
}

//πÈ≤¢≈≈–Ú
void GuiBingSort(vector<int> arr)
{
	printf("πÈ≤¢≈≈–Ú\n");
	int mid = 0;
	int lo = 0;
	int hi = 0;
	int k = 1;
	while (k < arr.size())
	{
		lo = 0;
		while (lo < arr.size())
		{
			hi = min(lo + k * 2 - 1, arr.size() - 1);
			mid = (hi - lo) / 2 + lo;
			bing(arr, lo, mid, hi);
			lo = hi + 1;
		}
		k *= 2;
	}


	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void swap(vector<int> &arr, int i, int j)
{
	int mid = arr[i];
	arr[i] = arr[j];
	arr[j] = mid;
}

void quickSort(vector<int> &arr, int lo, int hi)
{
	if (lo >= hi) return;
	int mid = lo;
	int i = lo + 1;
	int j = hi;

	while (i <= j)
	{
		if (arr[mid] < arr[i]) swap(arr, i, j--);
		else if (arr[mid] > arr[i]) swap(arr, i++, mid++);
		else i++;
	}

	quickSort(arr, lo, mid - 1);
	quickSort(arr, i, hi);
}

void QuickSort(vector<int> arr)
{
	printf("øÏÀŸ≈≈–Ú\n");
	quickSort(arr, 0, arr.size() - 1);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}


//¥Û∂•∂—πÊ‘Ú
void sink(vector<int> &arr, int k, int n)
{
	for (int i = k * 2 + 1; i <= n; i = i * 2 + 1)
	{
		if (i + 1 <= n&&arr[i]< arr[i + 1]) i++;

		if (arr[k] < arr[i])
		{
			swap(arr, k, i);
			k = i;
		}
		else break;
	}
}

//∂—≈≈–Ú
void headSort(vector<int> arr)
{
	printf("∂—≈≈–Ú\n");
	int N = arr.size() - 1;
	for (int i = (arr.size()) / 2 - 1; i >= 0; i--)
		sink(arr, i, N);

	for (int i = 0; i < arr.size(); i++)
	{
		swap(arr, 0, N--);
		sink(arr, 0, N);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

//Õ∞≈≈–Ú
void TongSort(vector<int> arr)
{
	printf("Õ∞≈≈–Ú\n");
	int min = 0;
	int max = 100;
	int len = max - min + 1;
	int *buckets = new int[max - min + 1];

	int *bags = new int[arr.size()];
	memset(buckets, 0, (max - min + 1) * sizeof(int));

	for (int i = 0; i < arr.size(); i++)
	{
		buckets[arr[i] - min]++;
	}

	for (int i = 1; i < len; i++)
	{
		buckets[i] = buckets[i] + buckets[i - 1];
	}
	for (int i = 0; i < arr.size(); i++)
	{
		int index = --buckets[arr[i] - min];
		bags[index] = arr[i];
	}
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = bags[i];
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	delete buckets;
	delete bags;
}

//ª˘ ˝≈≈–Ú
void JiShuSort(vector<int> arr)
{
	int min = 0;
	int max = 9;
	int count = 2;
	int len = max - min + 1;
	int *buckets = new int[len];
	int *bags = new int[arr.size()];

	int k = 1;
	while (count-- > 0)
	{
		memset(buckets, 0, len * sizeof(int));
		for (int i = 0; i < arr.size(); i++)
		{
			int index = ((arr[i] - min) / k) % 10;
			buckets[index]++;
		}
		for (int i = 1; i < len; i++)
		{
			buckets[i] = buckets[i] + buckets[i - 1];
		}
		for (int i = arr.size() - 1; i >= 0; i--)
		{
			int index = --buckets[((arr[i] - min) / k) % 10];
			bags[index] = arr[i];
		}
		for (int i = 0; i < arr.size(); i++)
		{
			arr[i] = bags[i];
		}

		k *= 10;
	}

	printf("ª˘ ˝≈≈–Ú\n");
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	delete buckets;
	delete bags;
}

int bSearch(vector<int> &arr, int lo, int hi, int target)
{
	if (lo == hi) return -1;
	int mid = (hi - lo) / 2 + lo;
	if (arr[mid] == target) return mid;
	else if (arr[mid] > target)
	{
		return bSearch(arr, lo, mid - 1, target);
	}
	return bSearch(arr, mid + 1, hi, target);
}

int bSearch(vector<int> &arr, int target)
{
	int lo = 0;
	int hi = arr.size() - 1;
	int mid;
	while (lo < hi)
	{
		mid = (hi - lo) / 2 + lo;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] > target)
		{
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}

	}
	return -1;
}

void binarySearch()
{
	vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };

	int index = bSearch(arr, 7);

	if (index != -1)
	{
		cout << "Find " << arr[index] << endl;
	}
	else
	{
		cout << "No Find";
	}

}

