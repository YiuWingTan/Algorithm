#include<iostream>
#include<vector>
using namespace std;



int main()
{
	vector<int> arr = { 54,2,3,66,3,2,5,414,5,5,1,85,8,5,-8,6,-4,-88,-3,0 };

	int min;
	int mid;
	for (int i = 0; i < arr.size(); i++)
	{
		min = i;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[min] > arr[j]) min = j;
		}
		if (min != i)
		{
			mid = arr[min];
			arr[min] = arr[i];
			arr[i] = mid;
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	getchar();
	return 0;
}