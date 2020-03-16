#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int rob(vector<int>& nums) {

	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];
	vector<int> ans;
	ans.resize(nums.size(),0);
	ans[0] = nums[0];
	ans[1] = nums[1];;

	for (int i = 2; i < nums.size(); i++)
	{
		ans[i] = max(ans[i-1],ans[i-2]+nums[i]);
	}

	return ans[ans.size()-1];
}

//环形条件下
int rob2(vector<int> nums) {

}


int main()
{
	cout << rob2({ 1,2,3,1 });

	getchar();
	return 0;
}

