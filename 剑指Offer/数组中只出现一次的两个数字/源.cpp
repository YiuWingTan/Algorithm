#include<iostream>
#include<vector>

using namespace std;

void slove(vector<int>&arr,vector<int> &result)
{
	int key = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		key = (key^arr[i]);
	}

	int val = 1;
	
	while ((val&key) != val) val = (val << 1);

	int t1 = 0, t2 = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if ((arr[i] & val) == val) t1 = (t1^arr[i]);
		else t2 = (t2^arr[i]);
	}
	result.push_back(t1);
	result.push_back(t2);
}


void text1()
{
	vector<int> arr = {2,4,3,6,3,2,5,5};
	vector<int> result;

	slove(arr,result);


	cout << "结果为 "<<result[0]<<"  "<<result[1]<<endl<<endl;


}


void text2()
{
	vector<int> arr = {};
	vector<int> result;

	slove(arr, result);


	cout << "结果为 " << result[0] << "  " << result[1] << endl << endl;

}

void text3()
{
	vector<int> arr = {};
	vector<int> result;

	slove(arr, result);


	cout << "结果为 " << result[0] << "  " << result[1] << endl << endl;

}

int main()
{
	text1();
	getchar();
	return 0;
}
