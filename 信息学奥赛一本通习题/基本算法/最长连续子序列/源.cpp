#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;


int longestConsecutive(vector<int>& nums) {

	map<int, int> st;
	int max = INT_MIN;

	for (int i = 0; i < nums.size(); i++)
	{
		if (st.find(nums[i]) == st.end())
		{
			st[nums[i]] = 0;
		}
		else st[nums[i]]++;
	}



	for (int i = 0; i < nums.size(); i++)
	{
		int count = st[nums[i]];

		int l = nums[i]-1;
		int r = nums[i]+1;

		//在左边寻找长度
		while (st.find(l) != st.end()&&st[l]!=0)
		{
			count += st[l];
			st[l] = 0;
			l--;
		}

		//在右边寻找长度
		while (st.find(r) != st.end())
		{
			count += st[r];
			st[r] = 0;
			r++;
		}

		if (count > max) max = count;

	}

	return max;
}

int main()
{


	getchar();
	return 0;
}



