#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	
	int sum = 0;
	int max = INT_MIN;

	for (int i = 0; i < nums.size(); i++)
	{
		if (sum < 0) sum = nums[i];
		 else sum += nums[i];
		if (sum > max) max = sum;
	}

	return max;
}
int main()
{
	vector<int> q{ -2,1,-3,4,-1,2,1,-5,4 };
	cout<<"最大连续子串和为"<< maxSubArray(q)<<endl;
	getchar();
}