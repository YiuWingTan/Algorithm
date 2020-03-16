/*
	主题：回溯 ，数组  难度 中等
*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> mid;

void find(vector<vector<int>>&result,vector<int>& candidates,int n,int target)
{
	if (n >= candidates.size()) return;
	int r = candidates[n];
	if (r > target) return;
	int i = 0,j = 0;
	for (; i <=target; i += r,j++)
	{
		if (i != 0) mid.push_back(r);
		if (i == target)
		{
			//获取到一个结果
			result.push_back(mid);
			j++;
			break;
		}
		find(result,candidates,n+1,target-i);
	}

	while (--j > 0) mid.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;

	sort(candidates.begin(),candidates.end());

	find(result,candidates,0,target);

	return result;
}

int main()
{
	vector<int> arr = {2,3,5};
	int target = 8;

	auto result = combinationSum(arr,target);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}


	getchar();
	return 0;
}