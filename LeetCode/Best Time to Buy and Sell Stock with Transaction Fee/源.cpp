#include<iostream>
#include<vector>
using namespace std;

int max(int a,int b)
{
	return a > b ? a : b;
}

int maxProfit(vector<int>& prices) {

	if (prices.size() == 0) return 0;

	int buy =INT_MAX,n = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		if (buy > prices[i])
		{
			buy = prices[i];
		}
		n = max(n,prices[i]- buy);
	}

	return n;
}


int main()
{
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };

	cout << maxProfit(arr)<<endl;


	getchar();
	return 0;
}
