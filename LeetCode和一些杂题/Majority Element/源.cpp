#include<iostream>
#include<vector>

using namespace std;




//使用多数投票算法
int majorityElement(vector<int>& nums) {

	int count = 0;
	int ans = 0;


	for (int i = 0; i < nums.size(); i++)
	{
		if (count == 0) ans = nums[i];
		if (ans == nums[i]) count++;
		else count--;

	}

	if (count >= 1) return ans;
	return INT_MAX;

}


int main()
{



	getchar();
	return 0;
}

