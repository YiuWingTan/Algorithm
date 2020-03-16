#include<iostream>
#include<vector>

using namespace std;

void swap(vector<vector<int>> &matrix,int i,int j,int r,int c )
{
	int mid = matrix[i][j];
	matrix[i][j] = matrix[r][c];
	matrix[r][c] = mid;
}
void show(vector<vector<int>> &matrix) {

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
//解决方案
void rotate(vector<vector<int>>& matrix) {


	int n = matrix.size();
	if (n == 0) return;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if(i!=j)
				swap(matrix,i,j,j,i);
		}
	}
	int h = 0,t = 0;
	for (int i = 0; i < n; i++)
	{
		h = n-1;
		t = 0;
		while (t < h)
		{
			swap(matrix,i,h--,i,t++);
		}
	}

}

/*测试用例*/
void text1()
{
	vector<vector<int>> matrix
	{
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	show(matrix);
	rotate(matrix);
	show(matrix);
	cout << endl << endl;
}
void text2()
{
	vector<vector<int>> matrix
	{
		{ 5, 1, 9,11 },
		{ 2, 4, 8,10 },
		{ 13, 3, 6, 7 },
		{ 15,14,12,16 }
	};

	show(matrix);
	rotate(matrix);
	show(matrix);
	cout << endl << endl;
}
void text3()
{
	vector<vector<int>> matrix
	{
		{1}
	};

	show(matrix);
	rotate(matrix);
	show(matrix);
	cout << endl << endl;
}
void text4()
{
	vector<vector<int>> matrix{};
	show(matrix);
	rotate(matrix);
	show(matrix);
	cout << endl << endl;
}

int main()
{
	text1();
	text2();
	text3();
	getchar();
	return 0;
}
