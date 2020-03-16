#include<iostream>
#include<vector>
using namespace std;

//���ֲ���
int binarySearch(vector<int> &nums,int lo,int hi,int target)
{
	int mid;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (nums[mid] < target)
		{
			lo = mid+1;
		}
		else if (nums[mid] > target)
		{
			hi = mid - 1;
		}
		else return true;
	}
	return false;
}


bool search(vector<int>& nums, int target) {

	if (nums.size() == 0) return false;

	int lo,hi,mid;
	lo = 0;
	hi = nums.size()-1;

	if (nums[0] < nums[nums.size() - 1]) return binarySearch(nums,0,nums.size()-1,target);
	mid = lo + ((hi - lo) / 2);
	//�ҵ��߽�λ��
	while (lo < hi)
	{
		
		cout << lo << "," << hi <<"," <<mid<<endl;
		//if (mid-1>=0&&nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) break;
		//mid ���ұ�
		if (nums[mid] <= nums[hi] && nums[mid] < nums[lo])
		{
			hi = mid;
		}
		else if (nums[mid] >= nums[lo] && nums[mid] > nums[hi])
		{
			//�����
			lo = mid;
		}
		else if (nums[mid] == nums[lo] && nums[mid] == nums[hi])
		{
			//�޷��ж�����߻����ұ�
			for(int i = lo;i<hi;i++)
				if (nums[i] > nums[i + 1])
				{
					mid = i + 1;
					break;
				}

			break;
		}
		if (lo == hi - 1)
		{
			mid = nums[lo] > nums[hi] ? hi : lo;
			break;
		}
		else mid = lo + ((hi - lo) / 2);
	}

	printf("�м�λ����%d\n",mid);

	
	if (target >= nums[mid] && target <= nums[nums.size() - 1]) return binarySearch(nums,mid,nums.size()-1,target);
	return binarySearch(nums, 0, mid, target);

}


void text1()
{
	vector<int> arr = {3,1,1,1,1};
	int target = 3;

	bool result = search(arr,target);
	if (result)
	{
		printf("YES\n");
	}
	else
		printf("No\n");
}

void text2()
{

}

void text3()
{

}


int main() {

	text1();

	getchar();
	return 0;
}