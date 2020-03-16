#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {

	vector<vector<int>> result;

	if (numRows == 0) return{};

	int count = 1;

	for (int i = 0; i < numRows; i++)
	{
		result.push_back({});
		result[i].resize(count,0);
		result[i][0] = 1;
		result[i][count - 1] = 1;

		for (int j = 1; j < count; j++)
		{
			if (result[i][j] == 0)
			{
				result[i][j] = result[i-1][j] + result[i-1][j-1];
			}
		}

		count++;
	}


	return result;

}


void show(vector<vector<int>>&arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}


int main()
{

	int row = 5;
	auto arr = generate(row);
	show(arr);
	getchar();
	return 0;
}