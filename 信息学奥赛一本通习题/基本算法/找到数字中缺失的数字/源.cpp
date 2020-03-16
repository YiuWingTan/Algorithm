#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {

	int n = nums.size()*(nums.size()+1)/2;

	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];

	}
	return n - sum;
}


int main()
{


	getchar();
	return 0;
}



