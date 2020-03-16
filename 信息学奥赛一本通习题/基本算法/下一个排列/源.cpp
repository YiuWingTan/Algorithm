#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void nextPermutation(vector<int>& nums)
{

	int first = 0;

	for (int i = nums.size()-1; i > 0; i--)
	{
		if (nums[i - 1] < nums[i]) {
			first = i-1;
			break;
		}
	}

	if (nums.size()<2||nums[first] >= nums[first + 1]) {
		sort(nums.begin(),nums.end());
		return ;
	}

	for (int i = nums.size() - 1; i > first; i--) {

		if (nums[i] > nums[first])
		{
			swap(nums[i],nums[first]);
			sort(nums.begin()+first+1,nums.end());
			return;
		}
	}


}


int main()
{


	getchar();
	return 0;
}
