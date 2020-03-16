#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>&nums, int i, int j)
{
	int mid = nums[i];
	nums[i] = nums[j];
	nums[j] = mid;
}
//ÊÖß£¿ìËÙÅÅĞò
void quickSort(vector<int> &arr,int lo,int hi)
{
	if (lo > hi) return;
	int i = lo+1;
	int k = lo;
	int j = hi;

	while (i <= j)
	{
		if (arr[k] > arr[i]) swap(arr,k++,i++);
		else if (arr[k] < arr[i]) swap(arr,i,j--);
		else i++;
	}
	quickSort(arr,lo,k-1);
	quickSort(arr,i,hi);
}



void permute(vector<vector<int>> &results,int begin,vector<int>& nums)
{
	if (begin == nums.size() - 1)
	{
		results.push_back(nums);
		return;
	}
	
	for (int i = begin; i < nums.size(); i++)
	{
		if (i != begin&&nums[i] == nums[begin]) continue;
		swap(nums,begin,i);
		permute(results,begin+1,nums);
		//swap(nums,begin,i);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {

	vector<vector<int>> results;
	
	if (nums.size() == 0) {
		results.push_back({});
		return results;
	}
	quickSort(nums, 0, nums.size() - 1);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i]<<" ";
	cout << endl;
	permute(results,0,nums);

	return results;
}

int main()
{

	vector<int> nums = {-1,2,0,-1,1,0,1};

	auto results = permuteUnique(nums);

	for (int i = 0; i < results.size(); i++)
	{
		for (int j = 0; j < results[i].size(); j++)
			cout << results[i][j]<<" ";
		cout << endl;
	}

	getchar();
	return 0;
}
