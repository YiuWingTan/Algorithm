#include<iostream>
#include<vector>

using namespace std;

bool binarySearch(vector<int>& arr,int lo,int hi,int target)
{

	int mid = lo + (hi - lo) / 2;

	while (lo != hi)
	{
		mid = lo + (hi - lo) / 2;
		if (arr[mid] == target) return true;
		else if (arr[mid] > target) hi = mid - 1;
		else lo = mid + 1;
	}
	return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {

	if (matrix.size() == 0) return false;

	int m = matrix.size();
	int n = matrix[0].size();

	if (matrix[0][0] > target) return false;

	for (int i = 0; i < m; i++)
	{
		if (matrix[i][n-1] > target)
		{
			return binarySearch(matrix[i],0,n-1,target);
		}
	}

	
	return false;
}
int main()
{

	getchar();
	return 0;
}