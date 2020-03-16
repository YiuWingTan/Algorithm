#include<iostream>
#include<vector>

using namespace std;

int min(int i,int j)
{
	return i > j ? j : i;
}

//获取最小金钱-动态规划
int getMinMoney(int P,vector<int> a)
{
	if (a.size() == 0 || a[a.size() - 1] > P) {
		throw "输入的数据有误";
	}
	int q = a.size();
	vector<int> aa;
	aa.push_back(0);
	for (int i = 0; i < a.size(); i++) aa.push_back(a[i]);
	aa.push_back(P+1);
	
	vector<vector<int>> dp;
	dp.resize(q+1);
	for (int i = 0; i < dp.size(); i++) dp[i].resize(q+2,0);

	for (int w = 2; w <=q+1; w++)
	{
		for (int i = 0; i+w < q+2; i++)
		{
			int j = i + w;
			int t = INT_MAX;
			for (int k = i+1; k < j; k++)
			{
				t = min(t,(dp[i][k] + dp[k][j]));
			}
			dp[i][j] = t + aa[j] - aa[i] - 2;
		}
	}

	return dp[0][q + 1];

}


void text1()
{
	vector<int> arr = {3};
	int P = 8;

	cout << "最小的金钱是 " << getMinMoney(P,arr)<<endl;
}

void text2()
{
	vector<int> arr = {3,6,14};
	int P = 20;

	cout << "最小的金钱是 " << getMinMoney(P, arr)<<endl;
}




int main()
{
	text1();
	text2();

	getchar();
	return 0;
}