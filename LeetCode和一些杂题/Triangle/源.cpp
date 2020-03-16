#include<iostream>
#include<vector>
using namespace std;

int min(int i,int j)
{
	return i > j ? j : i;
}

//使用原来的二维数组
int minimumTotal(vector<vector<int>>& triangle) {

	if (triangle.size() == 0) return 0;

	if (triangle.size() == 1) return triangle[0][0];
	
	int mm = INT_MAX;

	for (int i = 1; i < triangle.size(); i++)
	{
		mm = INT_MAX;
		for (int j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
			{
				triangle[i][j] += triangle[i-1][0];
			}
			else if (j == triangle[i].size() - 1)
			{
				triangle[i][j] += triangle[i - 1][triangle[i - 1].size()-1];
			}
			else
			{
				triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
			}

			if (triangle[i][j] < mm) mm = triangle[i][j];
		}
	}

	return mm;

}


int main()
{
	int min;
	vector<vector<int>> triangle =
	{
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};

	cout << minimumTotal(triangle);

	getchar();
	return 0;
}


