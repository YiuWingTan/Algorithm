#include<iostream>
#include<vector>

using namespace std;

//最大价值-动态规划最优解法
int getMaxValue(vector<vector<int>>&arr)
{
	int row = arr.size();
	if (row == 0) return 0;
	int col = arr[0].size();
	if (col == 0) return 0;
	int val;
	vector<int> dp;
	dp.resize(col,0);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int left = j-1>=0?dp[j-1]:0;
			int up = dp[j];
			dp[j] = left >= up ? (left + arr[i][j]):(arr[i][j] + up);
		}
	}
	return dp[col-1];
}


void text1()
{
	vector<vector<int>> arr =
	{
		{ 1,10,3,8 },
		{ 12,2,9,6 },
		{ 5,7,4,11 },
		{ 3,7,16,5 }
	};


	int val = getMaxValue(arr);

	printf("最大价值是%d\n",val );

}
void text2()
{
	vector<vector<int>> arr =
	{
		{ 1,10,3,8 }
	};


	int val = getMaxValue(arr);

	printf("最大价值是%d\n", val);
}
void text4()
{
	vector<vector<int>> arr =
	{
	};


	int val = getMaxValue(arr);

	printf("最大价值是%d\n", val);
}
void text3()
{
	vector<vector<int>> arr =
	{
		{ 1 },
		{ 12},
		{ 5 },
		{ 3 }
	};


	int val = getMaxValue(arr);

	printf("最大价值是%d\n", val);
}
void text5()
{
	vector<vector<int>> arr =
	{
		
		{ 12 }
	
	};


	int val = getMaxValue(arr);

	printf("最大价值是%d\n", val);
}

int main()
{
	
	text1();
	text2();
	text3();
	text4();
	text5();

	getchar();
	return 0;
}
