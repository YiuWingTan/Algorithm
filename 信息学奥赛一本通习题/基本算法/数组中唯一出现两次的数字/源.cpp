#include<iostream>
#include<vector>

using namespace std;


int findDuplicate(vector<int>& nums) {

	if (nums.size() == 0) return -1;

	int slow = 0;
	int fast = 0;
	
	do {
		slow = nums[slow];
		fast = nums[nums[fast]];
	} while (slow!=fast);


	//寻找环的长度
	int len = 0;
	int entry = 0;
	do {
		len++;
		fast = nums[fast];
		entry = nums[entry];
	} while (fast!=slow);

	while (entry != fast)
	{
		entry = nums[entry];
		fast = nums[fast];
	}

	return entry;
}

