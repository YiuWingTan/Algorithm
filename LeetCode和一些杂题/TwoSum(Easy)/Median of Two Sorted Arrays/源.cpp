#include<iostream>
#include<stack>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	int s1 = nums1.size();
	int s2 = nums2.size();
	int mid = (nums1.size() + nums2.size()) / 2;
	int i = 0;

	stack<int> mStack;

	while (i <= (mid+1))
	{
		if (i >= s1)mStack.push(nums2[i]);
		else if (i > s2) mStack.push(nums1[i]);
		else if (nums1[i] > nums2[i])mStack.push(nums2[i]);
		else mStack.push(nums1[i]);
		i++;
	}

	double result = 0.0;

	if (mid % 2 == 0)
	{
		mStack.pop();
		result = (double)mStack.top();
	}
	else
	{
		result = (double)mStack.top();
		mStack.pop();
		result = (result + mStack.top()) / 2;
	}

	return result;

}

int main()
{

}
