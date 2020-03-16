#include<iostream>
#include<vector>

using namespace std;


void rotate(vector<vector<int>>& matrix) {
	
	int len = matrix.size();

	for (int i = 0; i < len/2; i++)
	{
		for (int j = i; j <= len - (i+1); j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[len - (i+1)][j];
			matrix[len - (i + 1)][j] = matrix[len - (i+1)][len - (i+1)];
			matrix[len - (i + 1)][len - (j + 1)] = matrix[i][len - (i+1)];
			matrix[i][len - (i + 1)] = tmp;
		}
	}

}

int main()
{

	getchar();
	return 0;
}


