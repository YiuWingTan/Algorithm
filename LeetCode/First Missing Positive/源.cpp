
/*

难度：困难 主题 数组 ps 我做不出来
*/
#include<iostream>
#include<vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	
	int len = nums.size();

	for (int i = 0; i < len; i++)
		if (nums[i] <= 0) nums[i] = len+1;

	for (int i = 0; i < len; i++)
	{
		int val = abs(nums[i]) -1;
		if (val < len)
		{
			nums[val] = -abs(nums[val]);;
		}
	}

	for (int i = 0; i < len; i++)
		if (nums[i] > 0) return i+1;

	return len+1;
}


int main()
{
	vector<int> arr = { 1,1};
	int result = firstMissingPositive(arr);
	printf("First Missing PositiveΪ%d\n",result);

	getchar();
	return 0 ;
} 