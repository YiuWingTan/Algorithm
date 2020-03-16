#include<iostream>
#include<vector>

using namespace std;

/*
ʵ��Ҫ��
1.while (lo < hi) ��Ϊ��whileѭ������lo �� hi������������mid+1��mid-1 �����п��ܻ������ѭ��������lo��hiһֱ���
2.if (nums[mid] == nums[hi] && nums[mid] == nums[lo]) �� �����������ֵ����ȵ�ʱ���޷������жϵ�ǰ������������������������Ҫ���б������
3.hi = mid; 
4.if (nums[mid] > nums[hi]) lo = mid+1;
*/
int findMin(vector<int>& nums) {

	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return 1;


	int lo = 0, hi = nums.size()-1;
	int mid;
	while (lo < hi)
	{
		mid = lo + (hi - lo)/2;

		if (nums[mid] > nums[hi])
			lo = mid+1;
		else {
			if (nums[mid] == nums[hi] && nums[mid] == nums[lo])
			{
				//��������޷��ж�mid����һ��--���б������
				int min = nums[0];
				for (int i = 0; i < nums.size(); i++) if (min > nums[i]) min = nums[i];
				return min;

			}
			hi = mid;
		}
	}
	
	return nums[lo];
}




int main()
{
	vector<int> arr = {3,3,1,3};
	cout << findMin(arr)<<endl;

	getchar();
	return 0;
}