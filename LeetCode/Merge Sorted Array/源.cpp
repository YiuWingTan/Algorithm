#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	if (nums2.size() == 0) return;

	int index = nums1.size()-1;

	m--;
	n--;
	while (n >= 0)
	{
		if (nums1[m] > nums2[n])
		{
			nums1[index--] = nums1[m--];
		}
		else
		{
			nums1[index--] = nums2[n--];
		}
	}

}


int main()
{


}