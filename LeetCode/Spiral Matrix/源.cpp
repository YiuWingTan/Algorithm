#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {

	vector<int> result;

	if (matrix.size() == 0) return result;

	int topi, topj,downi,downj,i,j;
	i = j = topi = topj = 0;
	downi = matrix.size() - 1;
	downj = matrix[0].size() - 1;

	while (topi <= downi&&topj <= downj)
	{
		for (i = topi, j = topj; j <= downj;j++)
			result.push_back(matrix[i][j]);

		if (topi != downi)
		{
			for (i = topi+1, j = downj; i <= downi; i++)
				result.push_back(matrix[i][j]);
			if (topj!=downj)
			{
				for (i = downi, j = downj-1; j >= topj; j--)
					result.push_back(matrix[i][j]);
				for (j = topj, i = downi-1; i >= topi+1; i--)
					result.push_back(matrix[i][j]);
			}
		}

		topi++;
		topj++;
		downi--;
		downj--;
	}

	return result;
}

void text1()
{
	vector<vector<int>> matrix =
	{
		{ 1,2,3,4 },
		{ 5,6,7,8 },
		{ 9,10,11,12 }
	};
	vector<int> list = spiralOrder(matrix);

	for (int i = 0; i < list.size(); i++)
		cout << list[i] << " ";
	cout << endl;
}

void text2()
{
	vector<vector<int>> matrix =
	{
		{1,2,3}
	};
	vector<int> list = spiralOrder(matrix);

	for (int i = 0; i < list.size(); i++)
		cout << list[i] << " ";
	cout << endl;
}

void text3()
{
	vector<vector<int>> matrix =
	{
		{1},
		{2},
		{3}
	};
	vector<int> list = spiralOrder(matrix);

	for (int i = 0; i < list.size(); i++)
		cout << list[i] << " ";
	cout << endl;
}

void text4()
{
	vector<vector<int>> matrix =
	{
		{5}
	};
	vector<int> list = spiralOrder(matrix);

	for (int i = 0; i < list.size(); i++)
		cout << list[i] << " ";
	cout << endl;
}

int main()
{
	text1();
	text2();
	text3();
	text4();
	getchar();
	return 0;

}