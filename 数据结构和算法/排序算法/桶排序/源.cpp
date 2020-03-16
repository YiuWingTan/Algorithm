#include<iostream>
#include<vector>

using namespace std;


//Õ∞≈≈–Ú
void packSort(vector<int>&arr,int min,int max)
{
	if (arr.size() <= 1) return;
	vector<int> packed;
	vector<int> subArray;
	packed.resize(max- min+1,0);
	subArray.resize(arr.size());


	for (int i = 0; i < arr.size(); i++)
	{
		packed[arr[i] - min]++;
	}

	for (int i = 1; i < packed.size(); i++)
	{
		packed[i] += packed[i - 1];
	}

	for (int i = 0; i < arr.size(); i++)
	{
		int index = --packed[arr[i] - min];
		subArray[index] = arr[i];
	}
	for (int i = 0; i < subArray.size(); i++)
	{
		arr[i] = subArray[i];
	}


}

int main()
{
	vector<int> arr = { 1 };
	int min = -100;
	int max = 500;

	packSort(arr,min,max);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	getchar();
	return 0;
}