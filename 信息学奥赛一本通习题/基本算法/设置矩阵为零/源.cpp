#include<iostream>
#include<vector>

using namespace std;


void setZeroes(vector<vector<int>>& matrix) {

	bool set_row0 = false, set_col0 = false;
	int row = matrix.size();
	int col = matrix[0].size();


	for (int i = 0; i < row; i++)
	{
		if (matrix[i][0] == 0) {
			set_col0 = true;
			break;
		}
	}

	for (int j = 0; j < col; j++)
	{
		if (matrix[0][j] == 0)
		{
			set_row0 = true;
			break;
		}
	}


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}


	//行设置为0
	for (int i = 1; i < row; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	//将一列设置为0
	for (int j = 1; j < col; j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 0; i < row; i++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	if (set_row0) {
		for (int j = 0; j < col; j++) matrix[0][j] = 0;
	}
	if (set_col0)
	{
		for (int i = 0; i < row; i++) matrix[i][0] = 0;
	}
}


int main()
{


	getchar();
	return 0;
}


