#include<iostream>
#include<vector>

using namespace std;

int min(int a,int b)
{
	return a > b ? b : a;
}

//¶¯Ì¬¹æ»®
int minPathSum(vector<vector<int>>& grid) {

	if (grid.size() == 0) return 0;

	int row = grid.size();
	int col = grid[0].size();

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i - 1 >= 0 && j - 1 >= 0)
			{
				grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
			}
			else if (i - 1 >= 0)
			{
				grid[i][j] += grid[i-1][j];
			}
			else if (j - 1 >= 0)
			{
				grid[i][j] += grid[i][j-1];
			}
		}
	}

	return grid[row-1][col-1];
}

void change(string&str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '[') str[i] = '{';
		if (str[i] == ']') str[i] = '}';
	}
}


int manin()
{


	vector<vector<int>> grid = 
	{

	};
	int count = minPathSum(grid);


	getchar();
	return 0;
}