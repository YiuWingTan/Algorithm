#include<iostream>

#include<vector>

using namespace std;



int main()
{
	vector<int> arr = { 54,2,3,66,3,2,5,414,5,5,1,85,8,5,-8,6,-4,-88,-3,0 };

	int mid;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j+1 < arr.size() - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				mid = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = mid;
			}
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