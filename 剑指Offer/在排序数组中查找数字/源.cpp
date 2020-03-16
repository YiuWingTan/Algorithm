#include<iostream>
#include<vector>
using namespace std;

/*
 使用二分查找来找重复位置中的左右位置

*/

typedef int(*compare)(vector<int>&, int, int);

int find_left(vector<int>&arr,int index,int target)
{
	if (arr[index] > target) return 1;
	if (arr[index] < target) return -1;


	if (arr[index] == target)
	{
		if (index - 1 < 0 || index + 1 == arr.size()) return 0;
		if (arr[index - 1] < arr[index]) return 0;

		return 1;
	}
}

int find_right(vector<int>&arr, int index, int target)
{
	if (arr[index] > target) return 1;
	if (arr[index] < target) return -1;


	if (arr[index] == target)
	{
		if (index - 1 < 0 || index + 1 == arr.size()) return 0;
		if (arr[index+1] > arr[index]) return 0;

		return -1;
	}
}


//二分查找
int binaryFind(vector<int>&arr,compare cmp,int target)
{
	int lo = 0;
	int hi = arr.size() - 1;
	int mid = lo;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		int key = cmp(arr, mid, target);
		if (key > 0) hi = mid-1;
		else if (key < 0) lo = mid + 1;
		else return mid;
	}

	return -1;
}




int slove(vector<int> &arr,int tar)
{
	if (arr.size() == 0) return 0;
	int left = binaryFind(arr,find_left,tar);
	if (left == -1) 
		return 0;
	int right = binaryFind(arr, find_right, tar);

	return right - left + 1;
}


void text1()
{
	vector<int> arr = {1,2,3,3,3,3,4,5};
	int target = 3;

	cout << target<<" 有"<<slove(arr,target)<<" 个重复"<<endl;
}

void text2()
{
	vector<int> arr = { 1,1,1,1,2,3,3,3,3,4,5,5,5,5,5,5 };
	int target = 2;

	cout << target << " 有" << slove(arr, target) << " 个重复" << endl<<endl;
}

void text3()
{
	vector<int> arr = {1,1,1,1,1,1,1,1};
	int target = 1;

	cout << target << " 有" << slove(arr, target) << " 个重复" << endl;
}

int main()
{
	text3();

	getchar();
	return 0;

}



