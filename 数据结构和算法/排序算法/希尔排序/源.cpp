#include<iostream>
#include<vector>
using namespace std;

//Ï£¶ûÅÅĞò
void sSort(vector<int>&arr)
{
	if (arr.size() == 0) return;
	int n = 1;//µİÔöĞòÁĞ
	int mid;
	while (n < (arr.size() / 3)) n = n * 3 + 1;

	while (n >= 1)
	{
		for (int i = 0; i < arr.size(); i += n)
		{
			for (int j = i; j - n >= 0 && arr[j - n] > arr[j]; j -= n)
			{
				mid = arr[j];
				arr[j] = arr[j-n];
				arr[j - n] = mid;
			}
		}
		n /= 3;
	}



}

int main()
{
	vector<int> arr = { 54,2,3,66,3,2,5,414,5,5,1,85,8,5,-8,6,-4,-88,-3,0 };

	sSort(arr);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	getchar();
	return 0;
}