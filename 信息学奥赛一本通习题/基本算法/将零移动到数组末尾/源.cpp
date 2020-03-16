#include<iostream>
#include<vector>
using namespace std;


void moveZeroes(vector<int>& nums) {

	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0) count++;
		else if(count!=0){
			nums[i - count] = nums[i];
			nums[i] = 0;
		}
		
	}
}


int main()
{


	getchar();
	return 0;
}



