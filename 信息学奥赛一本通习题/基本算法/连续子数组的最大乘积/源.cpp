#include<iostream>
#include<vector>

using namespace std;



int maxProduct(vector<int>& nums) {
	
	if (nums.size() == 0) return 0;

	int max = nums[0];
	int dotMin = nums[0],dotMax = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		dotMin *= nums[i];
		dotMax *= nums[i];

		if (dotMin > dotMax) {
			dotMin ^= dotMax;
			dotMax ^= dotMin;
			dotMin = dotMin ^ dotMax;
		}

		if (dotMin > nums[i]) dotMin = nums[i];
		if (dotMax < nums[i]) dotMax = nums[i];

		if (max < dotMax) max = dotMax;
	}

	return max;
}



