#include<iostream>
#include<vector>

using namespace std;

/*
实现要点
1.while (lo < hi) 因为在while循环体中lo 和 hi的增量并不是mid+1和mid-1 所以有可能会出现死循环。导致lo和hi一直相等
2.if (nums[mid] == nums[hi] && nums[mid] == nums[lo]) 当 三个标记量的值都相等的时候无法进行判断当前是在左区域还是右区域所以需要进行暴力求解
3.hi = mid; 
4.if (nums[mid] > nums[hi]) lo = mid+1;
*/
int findMin(vector<int>& nums) {

	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return 1;


	int lo = 0, hi = nums.size()-1;
	int mid;
	while (lo < hi)
	{
		mid = lo + (hi - lo)/2;

		if (nums[mid] > nums[hi])
			lo = mid+1;
		else {
			if (nums[mid] == nums[hi] && nums[mid] == nums[lo])
			{
				//特殊情况无法判断mid在那一边--进行暴力解决
				int min = nums[0];
				for (int i = 0; i < nums.size(); i++) if (min > nums[i]) min = nums[i];
				return min;

			}
			hi = mid;
		}
	}
	
	return nums[lo];
}




int main()
{
	vector<int> arr = {3,3,1,3};
	cout << findMin(arr)<<endl;

	getchar();
	return 0;
}