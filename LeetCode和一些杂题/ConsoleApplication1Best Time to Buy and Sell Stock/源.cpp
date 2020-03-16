#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {

	if (prices.size() < 0) return 0;
	int min = prices[0];
	int max = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		if (min > prices[i]) min = prices[i];
		if ((prices[i] - min) > max) max = prices[i] - min;

	}
	return max;
}


int main() {

	vector<int> p{ 7,1,5,3,6,4 };

	cout << "最大利润是"<< maxProfit(p) <<endl;

	getchar();
}