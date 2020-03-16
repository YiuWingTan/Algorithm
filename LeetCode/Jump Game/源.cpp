#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
	����һ���ǳ��õ�����,�ӵݹ鵽��̬�滮��̰��
*/

//̰���㷨
bool canJump2(vector<int>& nums)
{
	if (nums.size() == 0 || nums.size() == 1) return true;
	
	vector<int> dp;
	int len = nums.size();
	dp.resize(len+1,0);
	dp[0] = 1;
	for (int i = 1; i <nums.size(); i++)
	{
		if (dp[i - 1] > i + nums[i - 1])
			dp[i] = dp[i - 1];
		else if (dp[i - 1] >= i) dp[i] = i + nums[i-1];
		else dp[i] = INT_MIN;
		printf("dp[%d] = %d\n",i,dp[i]);
		if (dp[i] >= len) return true;
	}
	return dp[len - 1] >= len;
}

//�ⷨ1�����������-�����ʱ
bool canJump1(vector<int>& nums) {

	if (nums.size() == 1 || nums.size() == 0) return true;

	stack<int> st;
	vector<bool> isVisited;
	isVisited.resize(nums.size(),false);
	st.push(0);
	isVisited[0] = true;
	int index = 0;
	while (!st.empty()&&!isVisited[nums.size()-1])
	{
		index = st.top();
		st.pop();
		for (int i = index; i<nums.size()&&i <= index + nums[index]; i++)
		{
			if (!isVisited[i])
			{
				isVisited[i] = true;
				st.push(i);
			}
		}
	}

	return isVisited[nums.size() - 1];

}


int main()
{

	vector<int> path = { 0,2,3 };

	printf("%s\n", canJump2(path)?"�ɴ�":"���ɴ�");

	getchar();
	return 0;
}