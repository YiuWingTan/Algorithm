#include<iostream>
#include<vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	
	cost.push_back(0);
	int n = cost.size();
	for (int i = 2; i < n; i++){
		cost[i] = cost[i - 1] < cost[i - 2] ? cost[i - 1] + cost[i] : cost[i - 2] + cost[i];
	}

	return cost[n-1];
}


int main()
{

	vector<int> q{ 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };

	cout << "×îÐ¡ÊÇ"<<minCostClimbingStairs(q)<<endl;
	getchar();
}