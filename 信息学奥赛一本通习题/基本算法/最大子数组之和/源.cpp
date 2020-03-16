#include<iostream>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums) {

	if (nums.size() == 0) return INT_MIN;

	int max = nums[0];
	int pre = nums[0];


	for (int i = 1; i < nums.size(); i++)
	{
		int val = pre + nums[i];
		if (val < nums[i]) pre = nums[i];
		else pre = val;

		if (pre > max) max = pre;
	}
	return max;
}



int getMin(int a,int b,int c)
{
	if (a < b) return a < c ? a : c;
	return b > c ? c : b;
}

int getMax(int a, int b, int c)
{
	if (a < b) return b > c ? b : c;
	return a > c ? a : c;
}

int maxProduct(vector<int> nums) {
	if (nums.size() == 0) return INT_MIN;

	int max = nums[0];
	int pre_max = nums[0];
	int pre_min = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		int val_min = pre_min * nums[i];
		int val_max = pre_max*nums[i];

		if (nums[i] != 0)
		{
			pre_max = getMax(val_max, nums[i], val_min);
			pre_min = getMin(val_max, nums[i], val_min);
			
		}
		else  {

			pre_min = 0;
			pre_max = 0;
		}

		if (pre_max > max) max = pre_max;
	}
	return max;
}

int main()
{
	cout << maxProduct({0,2});


	getchar();
	return 0;
}
