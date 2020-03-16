#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {

	sort(nums.begin(),nums.end());
	
	int cloest = INT_MAX;


	for (int i = 0; i < nums.size(); i++)
	{
		int l = i+1, r = nums.size()-1;
		int faketarget = target - nums[i];
		while (l < r)
		{
			int sum = nums[l] + nums[r];

			if (sum > faketarget)
			{
				r--;
			}
			else if(sum<faketarget) {
				l++;
			}
			else {
				return target;
			}

			if (cloest == INT_MIN||abs(target - sum-nums[i])<abs(target - cloest))
			{
				cloest = sum + nums[i];
			}

		}
	}
	return cloest;
}

