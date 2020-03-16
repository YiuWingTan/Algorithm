#include<iostream>
#include<vector>
using namespace std;


//根据数据位的大小排序
void cardinalSort(vector<int>&arr,int n)
{
	int min = 0;
	int max = 9;
	int div = 1;
	int base = 10;

	vector<int> packed;
	vector<int> subArray;
	packed.resize(max - min+1,0);
	subArray.resize(arr.size());

	while (n >= 1)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			int val =(int)(arr[i] / div)%base;
			packed[val - min]++;
		}

		for (int i = 1; i < packed.size(); i++)
		{
			packed[i] += packed[i-1];
		}

		for (int i = arr.size()-1; i>=0;i--)
		{
			int val = (int)(arr[i] / div) % base;
			int index = --packed[val - min];
			subArray[index] = arr[i];
		}

		for (int i = 0; i < arr.size(); i++)
		{
			arr[i] = subArray[i];
		}

		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < packed.size(); i++) packed[i] = 0;

		n--;
		div *= 10;
	}

}


int main()
{

	vector<int> arr = { 53, 3, 542, 748, 14, 214, 154, 63, 616 };

	cardinalSort(arr,3);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

	getchar();
	return 0;
}
