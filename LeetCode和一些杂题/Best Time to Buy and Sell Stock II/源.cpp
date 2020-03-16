#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {

	int max = 0;

	for (int i = 0; i < prices.size()-1; i++)
	{
		if (prices[i] < prices[i + 1]) max += prices[i + 1] - prices[i];
	}


	return max;
}


int main()
{
	

	getchar();
	return 0;
}