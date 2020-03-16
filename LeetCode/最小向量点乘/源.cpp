#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>&arr,int i,int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//快速排序
void quickSort(vector<int>&arr, int lo, int hi)
{
	if (lo >= hi) return;

	int i,j,k;
	i = lo+1;
	j = hi;
	k = lo;

	while (i <= j)
	{
		if (arr[k] < arr[i]) swap(arr,i,j--);
		else if (arr[k] > arr[i]) swap(arr,i++,k++);
		else i++;
	}

	quickSort(arr,lo,k-1);
	quickSort(arr,j+1,hi);

}


int getMinScalarProduct(vector<int> v1,vector<int> v2)
{
	if (v1.size() == 0 || v2.size() == 0) return 0;

	if (v1.size() != v2.size()) {
		throw "向量格式不正确";
		return INT_MAX;
	}

	quickSort(v1,0,v1.size()-1);
	quickSort(v2,0,v2.size()-1);

	int j = v1.size()-1;
	int sum= 0;
	for (int i = 0; i < v1.size(); i++,j--)
	{
		sum += v1[i]*v2[j];
	}
	return sum;
}


int main()
{
	vector<int> v1 = {1,1,1,1};
	vector<int> v2 = {1,1,1,1};

	cout << "最小是 "<<getMinScalarProduct(v1,v2)<<endl;


	getchar();
	return 0;
}
