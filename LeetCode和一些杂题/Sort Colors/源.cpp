#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void swap(vector<int>& nums,int i,int j)
{
	int mid = nums[i];
	nums[i] = nums[j];
	nums[j] = mid;
}

void sortColors(vector<int>& nums) {

	if (nums.size() == 0) return;

	int lo ,hi;
	hi = nums.size() - 1;
	lo = 0;

	for (int i = 0; i <=hi;)
	{
		if (nums[i] == 1) 
			i++;
		else if (nums[i] == 0)
		{
			if (lo == i)
			{
				lo++;
				i++;
			}
			else 
				swap(nums,i,lo++);
		}
		else if (nums[i] == 2)
			swap(nums,i,hi--);
		
	}
}


int main()
{
	vector<int> nums = { 2,0,1};

	sortColors(nums);

	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i]<<" ";
	}

	getchar();
	return 0;
}