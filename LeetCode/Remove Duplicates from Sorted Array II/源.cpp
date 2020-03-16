#include<iostream>
#include<string>
#include<vector>
using namespace std;


int removeDuplicates(vector<int>& nums) {

	int n = nums.size();
	
	if (n <= 2) return n;
	
	int i, j,mid;
	i = j = 2;


	while (i < n&&j < n) {

		while (j < n&&nums[i-1]>nums[j])j++;

		if (j == n || nums[j] == nums[i - 2]) {
			j++;
			continue;
		}

		mid = nums[i];
		nums[i] = nums[j];
		nums[j] = mid;

		i++;
		j++;
	}

	return i;
}


int main()
{
	vector<int> arr = { 0,0,1,1,1,1,2,3,3 };

	int len = removeDuplicates(arr);
	printf("³¤¶ÈÎª:%d\n",len);
	for (int i = 0; i < len; i++)
		cout << arr[i]<<" ";

	cout << endl;




	getchar();
	return 0;
}