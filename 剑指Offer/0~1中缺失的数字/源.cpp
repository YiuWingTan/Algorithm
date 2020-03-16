#include<iostream>
#include<vector>
using namespace std;



int find(vector<int>&arr)
{
	if (arr.size() == 0) return INT_MIN;

	int lo = 0;
	int hi = arr.size()-1;

	while (lo <= hi)
	{
		int mid = lo + ((hi - lo) >> 1);

		if (arr[mid] == mid) lo = mid+1;
		else if (arr[mid] != mid && (mid - 1 < 0 || mid + 1 >= arr.size() || arr[mid - 1] == mid-1)) return mid;
		else if (arr[mid] != mid) hi = mid - 1;

	}
	return INT_MIN;
}
void text1()
{
	vector<int> arr = {1};

	int num = find(arr);

	if (num >= 0) cout << "È±ÉÙ" << num<<endl;
	else cout << "²»È±\n";
	cout << endl;
}


int main()
{
	text1();

	getchar();
	return 0;
}