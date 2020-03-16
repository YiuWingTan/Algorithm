/*
	难度 简单 主题 双指针
*/
#include<vector>
#include<iostream>

using namespace std;


int removeElement(vector<int>& nums, int val) {

	int lo = 0;
	int hi = 0;

	for (; hi < nums.size(); hi++)
	{
		if (nums[hi] != val&&lo!=-1)
		{
			nums[lo] = nums[hi];
			nums[hi] = val;
			lo++;
		}
		else if (nums[hi] == val&&lo == -1) lo = hi;
	}

	return lo==-1?nums.size():lo;
}


int main()
{
	vector<int> nums{ 0,1,2,2,3,0,4,2 };

	int len = removeElement(nums,2);


	for (int i = 0; i < len; i++)
		printf("%d ",nums[i]);

	getchar();
	return 0;
}