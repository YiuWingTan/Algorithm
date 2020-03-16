#include<iostream>
#include<vector>
using namespace std;

vector<int> best;

int max(int i, int j)
{
	return i > j ? i : j;
}

int rob(vector<int>& nums) {
	if (nums.size <= 0) return 0;
	best.resize(nums.size());
	best[0] = nums[0];
	best[1] = nums[0] > nums[1] ? nums[0] : nums[1];

	for (int i = 2; i < nums.size(); i++)
	{
		best[i] = max(best[i-1],best[i-2]+nums[i]);
	}
	return best[nums.size()-1];
}

int main()
{
	vector<int> r = {1,2,3,1};
	cout<<"最大价值为"<<rob(r)<<endl;
	getchar();
}