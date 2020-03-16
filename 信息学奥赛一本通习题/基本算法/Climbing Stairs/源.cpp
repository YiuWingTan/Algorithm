#include<iostream>
#include<vector>
using namespace std;

static vector<int> ans = {1,2};
int climbStairs(int n) {

	if (n < ans.size()) return ans[n];


	for (int i = ans.size() - 1; i <= n; i++)
	{
		int val = ans[i]+ans[i-1];
		ans.push_back(val);
	}

	return ans[n];

}

int main()
{


	getchar();
	return 0;
}


