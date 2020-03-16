/*
	难度 简单 主题 
*/
#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {

	if (nums.size() <= 0) return 0;

	int j = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		
	}

	return nums.size();

}

int main()
{
	getchar();
	return 0;
}

/*
int removeDuplicates(vector<int>& nums) {
auto length = nums.size();
if (!length)
return length;
auto res = 0;
for (auto i = 1; i < length; ++i)
{
if (nums[res] != nums[i])
{
nums[++res] = nums[i];
}
}
return ++res;
}
*/