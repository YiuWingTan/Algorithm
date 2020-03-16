#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int maxArea(vector<int>& height) {

	int i = 0, j = height.size() - 1;
	int max = INT_MIN;

	while (i < j)
	{
		if (max <min(height[i] , height[j])*(j-i))
		{
			max = height[i] * height[j];
		}

		if (height[i] > height[j])
		{
			j--;
		}
		else if (height[i] < height[j])
		{
			i++;
		}
		else
		{
			i++, j--;
		}
	}
	return max;
}



int main()
{


	getchar();
	return 0;
}
