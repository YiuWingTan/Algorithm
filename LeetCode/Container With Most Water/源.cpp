#include<vector>
#include<iostream>

using namespace std;

int abs(int v)
{
	return v > 0 ? v : -v;
}

int maxArea(vector<int>& height) {

	int max = 0;
	int i, j;
	i = 0;
	j = height.size()-1;
	int v =0;

	while (i < j)
	{
		v = abs(height[i]-height[j])*(j-1+1);
		if (height[i] < height[j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	return max;
}


int main()
{


	getchar();
	return 0;
}