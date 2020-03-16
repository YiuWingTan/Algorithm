#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {

	auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second; };

	vector<int> result;
	map<int, int> mm;
	vector<pair<int, int>> arr;
	int count = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (mm.find(nums[i]) == mm.end())
		{
			arr.push_back(pair<int, int>(nums[i], 1));
			mm[nums[i]] = count++;
		}
		else {
			arr[mm[nums[i]]].second++;;
		}
	}


	make_heap(arr.begin(), arr.end(), cmp);


	for (int i = 0; i < k; i++)
	{
		result.push_back(arr[0].first);
		arr.pop_back();
		pop_heap(arr.begin(), arr.end(),cmp);
		
	}

	return result;

}





