#include<iostream>
#include<vector>

using namespace std;

void slove(vector<vector<int>>&result,vector<int>&nums,vector<int>&ans,int n,int k)
{
	if (k == 0) {
		result.push_back(ans);
		return;
	}
	
	for (int i = n; i <= nums.size() - k; i++)
	{
		ans[ans.size() - k] = nums[i];

		slove(result,nums,ans,i+1,k-1);
		while (i + 1 <= nums.size() - k&&nums[i] != nums[i + 1])i++;
	}
}

vector<vector<int>> subsetsWithDup(vector<int> nums) {

	vector<vector<int>> result;
	vector<int> ans;

	for (int i = 0; i <= nums.size(); i++)
	{
		ans.resize(i);
		slove(result,nums,ans,0,i);
	}
	return result;
}


int main()
{

	//auto list = subsets({1,2,3});


	for (auto n : list)
	{
		for (auto i : n)
		{
			cout << i << "  ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}


