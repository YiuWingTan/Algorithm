#include<iostream>
#include<vector>
#include<string>
using namespace std;

int count = 0;
bool isvaild(vector<int>&ans,int k)
{
	for (int i = 0; i < k; i++)
	{
		if (i - k == ans[i] - ans[k] || k - i == ans[i] - ans[k]) return false;
	}
	return true;
}
void premution(vector<vector<string>>&result,vector<int>&arr,vector<string>&ans,int k)
{
	if (k >= arr.size())
	{
		//判断并添加进入结果集中
		int count0 = 0, count1 = 0;
		int len = arr.size();
		for (int i = 0; i < len; i++) {

			for (int j = 0; j < len; j++)
			{
				if (arr[i] == j) ans[i][j] = 'Q';
				else ans[i][j] = '.';

			}
		}
		result.push_back(ans);
		return;
	}


	for (int i = k; i < arr.size(); i++)
	{
		swap(arr[i],arr[k]);
		if(isvaild(arr,k))
			premution(result,arr,ans,k+1);
		swap(arr[i], arr[k]);
	}


}
vector<vector<string>> solveNQueens(int n) {

	vector<vector<string>> result;
	vector<string> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i].resize(n, '.');
	}


	vector<int> arr(n,0);
	for (int i = 0; i < n; i++) arr[i] = i;

	premution(result,arr,ans,0);


	return result;
}

int main()
{
	auto result = solveNQueens(5);

	for (auto list : result)
	{
		for (auto str : list)
		{
			cout << str << endl;
		}
		cout << endl<<endl;
	}

	getchar();
	return 0;
}



