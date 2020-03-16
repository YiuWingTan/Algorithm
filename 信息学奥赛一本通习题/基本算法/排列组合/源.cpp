#include<iostream>
#include<vector>

using namespace std;

void slove(vector<int>&arr,int k,vector<vector<int>>&result)
{
	if (k >= arr.size())
	{
		result.push_back(arr);
		return;
	}

	for (int i = k; i < arr.size(); i++)
	{
		swap(arr[i],arr[k]);
		slove(arr,k+1,result);
		swap(arr[i],arr[k]);
	}

}

vector<vector<int>> permute(vector<int>& nums) {

	vector<vector<int>> result;

	slove(nums, 0, result);

	return result;

}


void quickSort(vector<int>&arr, int lo, int hi)
{
	if (lo >= hi) return;

	int i = lo + 1, k = lo, j = hi;

	while (i <= j)
	{
		if (arr[i] > arr[k])
		{
			swap(arr[i],arr[j--]);
		}
		else if (arr[i] < arr[k])
		{
			swap(arr[i++],arr[k++]);
		}
		else {
			i++;
		}
	}

	quickSort(arr,lo,k-1);
	quickSort(arr,j+1,hi);

}

void permute(vector<int>&arr, int k, vector<vector<int>> &result, vector<int> &ans)
{
	if (k >= arr.size()) {
		result.push_back(ans);
		return ;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (used[i]) continue;

		//避免在同一个位置上使用过了相同的值
		if (i - 1 >= 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;

		used[i] = true;

		ans[k] = arr[i];

		permute(arr,k+1,result,ans);

		used[i] = false;

	}
}


vector<bool> used;
vector<vector<int>> permuteUnique(vector<int>& nums) {

	vector<vector<int>> results;
	vector<int> ans;
	used.resize(nums.size(),false);
	ans.resize(nums.size());
	if (nums.size() == 0) {
		results.push_back({});
		return results;
	}
	quickSort(nums, 0, nums.size() - 1);
	
	permute(nums, 0, results, ans);

	return results;
}