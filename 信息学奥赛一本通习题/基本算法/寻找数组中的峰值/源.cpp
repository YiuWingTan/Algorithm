#include<iostream>
#include<vector>
using namespace std;


int findPeakElement(vector<int>& nums) {

	int lo = 0,hi = nums.size()-1;

	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (lo == hi) return lo;

		if (nums[mid] < nums[mid + 1])
		{
			lo = mid+1;
		}
		else {
			hi = mid;
		}

	}
	return 0;
}

int main()
{


	getchar();
	return 0;
}


