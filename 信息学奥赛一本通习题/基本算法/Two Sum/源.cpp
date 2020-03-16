#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


//������û�б�����������
vector<int> twoSum(vector<int>& nums, int target) {

	map<int, int> m;
	
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = i;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		
		if (m.find(target - nums[i]) != m.end()&&i!= m[target - nums[i]]) return{i,m[target - nums[i]]};


	}
	return{};
}

int binarySearch(vector<int>&arr,int lo,int hi,int target)
{

	int mid;

	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;

		if (arr[mid] > target)
		{
			hi = mid-1;
		}
		else if (arr[mid] < target)
		{
			lo = mid + 1;
		}
		else return mid;
	}
	return -1;
}

//�������Ѿ�����������
/*
-˫ָ�뷨
-���ֲ���
*/
vector<int> twoSum(vector<int>& numbers, int target) {

	/*int lo = 0, hi = numbers.size() - 1;

	while (lo < hi)
	{
		int val = numbers[lo] + numbers[hi];

		if (val < target)
		{
			lo++;
		}
		else if (val > target)
		{
			hi--;
		}
		else return{lo+1,hi+1};

	}*/

	return{};


}


//����֮��Ϊ0
/*
	ʹ�ö���ѭ���ڲ��������֮�͵�Ѱ��
	ʱ�临�Ӷ�ΪO(n^2)
*/
vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> result;
	sort(nums.begin(),nums.end());

	for (int i = 0; i < nums.size(); i++)
	{
		int lo = i + 1,hi = nums.size()-1;
		int tar = nums[i];
		while (lo < hi)
		{
			int val = nums[lo] + nums[hi];
			if (val > tar)
			{
				hi--;
			}
			else if (val < tar)
			{
				lo++;
			}
			else {
				result.push_back({ nums[i],nums[lo],nums[hi] });
				while (lo+1 <= hi&&nums[lo] == nums[lo + 1]) lo++;
				while (hi-1 >= lo&&nums[hi] == nums[hi - 1]) hi--;
				hi--;
				lo++;
			}
		}

		while (i+1 < nums.size() && nums[i] == nums[i + 1]) i++;
	}

	return result;
}


int main()
{


	getchar();
	return 0;
}