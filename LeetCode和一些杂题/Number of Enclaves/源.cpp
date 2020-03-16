#include<iostream>
#include<vector>

using namespace std;
int row;
int col;
void dfs(vector<vector<int>>&arr,int i,int j)
{
	if (i < 0 || i >= row) return;
	if (j < 0 || j >=col) return;
	if (arr[i][j] == 0) return;

	arr[i][j] = 0;

	dfs(arr,i+1,j);
	dfs(arr,i-1,j);
	dfs(arr,i,j+1);
	dfs(arr,i,j-1);
}

int numEnclaves(vector<vector<int>>& A) {

	if (A.size() == 0) return 0;
	
	row = A.size();
	col = A[0].size();
	int num = 0;
	for (int i = 0; i < row; i++)
	{
		if (A[i][0] == 1) dfs(A,i,0);
		if (A[i][col - 1] == 1) dfs(A,i, col -1);
	}
	for (int j = 0; j < col; j++)
	{
		if (A[0][j] == 1) dfs(A,0,j);
		if (A[row - 1][j] == 1) dfs(A, row -1,j);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (A[i][j] == 1) num++;
		}
	}

	return num++;

}


int main()
{
	vector<vector<int>> arr = 
	{
		{0,0,1,1,0,0,0,0,0,1},
		{1,1,0,1,0,0,1,0,0,1},
		{1,1,0,0,1,0,1,1,0,0},
		{1,0,0,1,0,0,0,0,0,1},
		{0,0,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{1,0,1,0,1,1,1,0,1,0},
		{0,1,1,1,0,0,1,0,0,1},
		{0,1,1,0,0,1,0,1,1,0},
		{1,0,1,1,0,0,1,1,0,0},
		{1,0,1,0,1,1,1,0,0,1}
	};


	cout<< numEnclaves(arr);



	getchar();
	return 0;
}
