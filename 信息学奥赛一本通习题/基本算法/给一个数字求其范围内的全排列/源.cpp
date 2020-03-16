#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void permutation(vector<vector<int>>&result,vector<int>&ans,int n)
{
	if (n >= ans.size()-1)
	{
		result.push_back(ans);
		return;
	}

	for (int i = n; i < ans.size(); ++i)
	{
		swap(ans[i],ans[n]);
		permutation(result,ans,n+1);
		swap(ans[i],ans[n]);
	}

}


void slove(int n)
{
	vector<vector<int>> result;
	vector<int> ans;
	ans.resize(n);
	for (int i = 0; i < n; i++)
	{
		ans[i] = i+1;
	}

	permutation(result,ans,0);

	cout << result.size() << endl;
	for (auto l : result)
	{
		for (auto n : l)
		{
			cout << n<<" ";
		}
		cout << endl;
	}
}

int main()
{
	slove(3);

	getchar();
	return 0;
}



