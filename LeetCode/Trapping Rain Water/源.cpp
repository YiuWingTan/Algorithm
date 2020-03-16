/*
难度：困难 主题 双指针 栈
*/

#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {

	int container = 0;

	int len = height.size();

	int right = 0;

	for (int i = 0; i < len; i++)
	{
		if (i + 2 < len&&height[i] > height[i + 1])
		{
			right = i + 2;
			int max = i+2;
			while (right < len)
			{
				if (height[max] <= height[right]) max = right;
				if (height[i] <= height[right]) break;
				right++;
			}
			if (height[max] <= height[i + 1]) { continue; }

			right = max;
			int val = height[max] < height[i] ? height[max]:height[i];

			for (int j = i+1; j <= right - 1; j++)
			{
				container += val - height[j];
			}

			i = right - 1;
		}
	}

	return container;

}


int main()
{
	vector<int> arr = { 4,2,3 };
	int result = trap(arr);
	printf("结果是%d\n",result);
	getchar();
	return 0;
}