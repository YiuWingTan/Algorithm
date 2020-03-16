#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		
		sums = new int[nums.size()];
		sums[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			sums[i] = nums[i]+sums[i-1];
		}
	}

	int sumRange(int i, int j) {
		if (i == 0) return sums[j];
		return sums[j] - sums[i-1];
	}
private:
	int *sums;
};

int main()
{
	vector<int> container = { -2,0,3,-5,2,-1 };
	NumArray na(container);


	cout << "ֵΪ"<<na.sumRange(0,5);

	getchar();
}