/*
ԭ��-��������
�㷨-��̬�滮
*/

#include<iostream>
#include<vector>
using namespace std;

int numTrees(int n) {

	static vector<int> dp = {1,1,2,5};
	if (n < 0) return 0;
	if (n < dp.size() - 1) return dp[n];
	int val;
	//��̬�滮-״̬����=dp[n] = ��dp[i]dp[n-i-1],i��0��n-1
	for (int k = dp.size(); k <= n; k++)
	{
		val = 0;
		for (int i = 0; i <= k - 1; i++)
		{
			val += dp[i] * dp[k-i-1];
		}
		dp.push_back(val);
	}

	return dp[n];
}


int main()
{
	int n = 5;

	int target = numTrees(n);

	printf("�ܹ������Ľṹ��:%d\n",target);

	getchar();
	return 0;
}