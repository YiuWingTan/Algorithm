#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>&arr,int i,int j)
{
	int mid = arr[i];
	arr[i] = arr[j];
	arr[j] = mid;
}

void sink(vector<int>&arr,int i,int n)
{
	int k;
	while ((i * 2 + 1) <= n)
	{
		k = i * 2+1;
		if (k + 1 <= n && arr[k] < arr[k + 1]) k++;
		if (arr[k] > arr[i]) { swap(arr, k, i); i = k; }
		else break;
		
	}
}


void hSort(vector<int>&arr)
{
	if (arr.size() <=1) return;

	int len = arr.size()-1;

	for (int i = arr.size() / 2 - 1; i >= 0; i--)
	{
		sink(arr,i, len);
	}

	
	for (int i = 0; i < arr.size(); i++)
	{
		swap(arr,0,len--);
		sink(arr,0,len);
	}

}


int main() {

	vector<int> arr2 = { 54,2,3,66,3,2,5,414,5,5,1,85,8,5,-8,6,-4,-88,-3,0 };

	hSort(arr2);

	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	getchar();
	return 0;
}
