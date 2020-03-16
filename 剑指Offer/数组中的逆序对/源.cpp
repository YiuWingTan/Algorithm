#include<iostream>
#include<vector>

using namespace std;


int get(vector<int>&arr,int lo,int hi)
{
	if (lo == hi) return 0;
	vector<int> tmp;
	tmp.resize(hi - lo+1,0);
	int mid = lo +(hi - lo)/2;

	int count = get(arr,lo,mid)+get(arr,mid+1,hi);

	//计算左右两个数组合并后的逆序对
	int i = mid;
	int j = hi;
	int index = tmp.size()-1;

	while (index >= 0)
	{
		if (i < lo) tmp[index--] = arr[j--];
		else if (j <= mid) tmp[index--] = arr[i--];
		else if (arr[i] <= arr[j]) tmp[index--] = arr[j--];
		else
		{
			count += (j - mid);
			tmp[index--] = arr[i--];
		}
	}
	index = 0;
	for (int i = lo; i <= hi; i++)
	{
		arr[i] = tmp[index++];
	}

	return count;
}

int getInverstOrder(vector<int>arr)
{
	if (arr.size() <= 1) return 0;

	return get(arr,0,arr.size()-1);

}

void textf1()
{
	vector<int> arr = { 1,2,3,4,5,6,7,8,9};
	int count = getInverstOrder(arr);
	for (int i = 0; i < arr.size(); i++) cout << arr[i]<<" ";
	cout <<endl<<"逆序对的数量为: " <<count<<endl;
}
void textf2()
{
	vector<int> arr = { 9,8,7,6,5,4,3,2,1};
	int count = getInverstOrder(arr);
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	cout << endl << "逆序对的数量为: " << count << endl;
}
void textf3()
{
	vector<int> arr = { 1,1,1,1,1,1,1,1,1};
	int count = getInverstOrder(arr);
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	cout << endl << "逆序对的数量为: " << count << endl;
}
void textf4()
{
	vector<int> arr = {};
	int count = getInverstOrder(arr);
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	cout << endl << "逆序对的数量为: " << count << endl;
}




int main()
{
	textf1();
	textf2();
	textf3();
	textf4();


	getchar();
	return 0;
}
