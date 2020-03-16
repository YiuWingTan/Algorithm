/*
主题 数组，回溯，难度 中等
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> result;
vector<int> mid;

void find(vector<int> &candidates,int target,int m,bool isget)
{
	if (m>=candidates.size()||candidates[m] > target) return;

	if (candidates[m] == target)
	{
		mid.push_back(candidates[m]);
		result.push_back(mid);
		mid.pop_back();
	}
	else
	{
		if (m - 1 >= 0 && candidates[m - 1] == candidates[m] && !isget)
		{
			//进行跳跃
			while (m + 1 < candidates.size() && candidates[m] == candidates[m + 1]) m++;
			find( candidates, target, m+1, false);
			return;
		}
		mid.push_back(candidates[m]);
		find(candidates,target - candidates[m],m+1,true);
		mid.pop_back();


		find(candidates,target,m+1,false);
	}

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

	sort(candidates.begin(),candidates.end());
	find(candidates,target,0,true);

	return result;
}

int main()
{
	vector<int> arr = { 2,5,2,1,2 };
	int target = 5;

	auto result = combinationSum2(arr,target);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j]<<"  ";
		}
		cout << endl;
	}

	getchar();

	return 0;
}