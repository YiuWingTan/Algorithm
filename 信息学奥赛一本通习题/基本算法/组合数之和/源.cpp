#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void find(vector<vector<int>>&result,vector<int>&arr,vector<int>&ans,int n,int target)
{
	if (target == 0)
	{
		result.push_back(ans);
		return;
	}

	for (int i = n; i < arr.size(); i++)
	{
		if (arr[i] > target) break;
		ans.push_back(arr[i]);
		find(result,arr,ans,i,target-arr[i]);
		ans.pop_back();
	}

}


vector<vector<int>> combinationSum(vector<int> candidates, int target)
{
	vector<vector<int>> result;
	vector<int> ans;
	sort(candidates.begin(),candidates.end());
	find(result,candidates,ans,0,target);

	return result;
}

int main()
{
	auto list = combinationSum({ 2,3,6,7 },7);

	for (auto l : list)
	{
		for (auto n : l)
		{
			cout << n << " ";
		}
		cout << endl;
	}


	getchar();
	return 0;
}
