#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(vector<int> &nums,int i,int j)
{
	int mid = nums[i];
	nums[i] = nums[j];
	nums[j] = mid;
}


void quickSort(vector<int> &nums,int lo,int hi)
{
	if (lo >= hi) return;
	int key = nums[lo];
	int i = lo + 1;
	int j = hi;
	int s = lo;

	while (lo <= hi)
	{

	}
}

void nextPermutation(vector<int>& nums) {

	if (nums.size() <=1) return;

	int left;
	for (left = nums.size() - 1; left >0; left--)
	{
		if (nums[left - 1] < nums[left]) break;
	}

	if (left >0)
	{
		//数组是逆序的要进行排序
		for (int i = nums.size()-1; i < nums.size(); i--)
		{
			if (nums[i] > nums[left-1])
			{
				swap(nums, i, left-1);
				sort(nums.begin()+left,nums.end());
				return;
			}
		}
	}
	sort(nums.begin(),nums.end());
}

int main() {

	vector<int> nums = {3,2,1};
	nextPermutation(nums);

	for (auto n = nums.begin(); n != nums.end(); n++)
		cout << "  " << *n;

	getchar();
	return 0;
}