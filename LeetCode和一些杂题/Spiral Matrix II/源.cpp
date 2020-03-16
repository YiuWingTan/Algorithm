#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {

	vector<vector<int>> result;
	if (n == 0) return result;
	result.resize(n);
	for (int i = 0; i < n; i++)
	{
		result[i].resize(n);
	}

	int topi, topj, downi, downj, i, j,count;
	i = j = topi = topj = 0;
	downi = n - 1;
	downj = n - 1;
	count = 1;

	while (topi <= downi&&topj <= downj)
	{
		for (i = topi, j = topj; j <= downj; j++)
			result[i][j] = count++;

		if (topi != downi)
		{
			for (i = topi + 1, j = downj; i <= downi; i++)
				result[i][j] = count++;
			if (topj != downj)
			{
				for (i = downi, j = downj - 1; j >= topj; j--)
					result[i][j] = count++;
				for (j = topj, i = downi - 1; i >= topi + 1; i--)
					result[i][j] = count++;
			}
		}

		topi++;
		topj++;
		downi--;
		downj--;
	}

	return result;


}



int main()
{
	int n = 3;
	auto list = generateMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << list[i][j] << " ";
		cout << endl;
	}

	getchar();
	return 0;

}