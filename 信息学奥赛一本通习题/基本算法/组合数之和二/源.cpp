#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void find(vector<vector<int>>&result,vector<int>&arr,vector<int>&ans,int k,int target)
{
	if (target == 0)
	{
		result.push_back(ans);
		return;
	}

	for (int i = k; i < arr.size(); i++)
	{
		if (arr[i] > target) break;
		ans.push_back(arr[i]);
		find(result, arr, ans, i + 1, target - arr[i]);
		ans.pop_back();

		while (i + 1 < arr.size() && arr[i] == arr[i + 1])i++;

	}


}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> ans;
	sort(candidates.begin(),candidates.end());
	find(result,candidates,ans,0,target);
	return result;
}



int main()
{


	getchar();
	return 0;
}
