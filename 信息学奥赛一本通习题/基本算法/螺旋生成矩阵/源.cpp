#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> generateMatrix(int n) {
	
	vector<vector<int>> res;
	res.resize(n);
	for (int i = 0; i < n; i++)
		res[i].resize(n);

	int r0 = 0, c0 = 0;
	int r1 = n - 1, c1 = n - 1;
	int count = 1;
	int i = 0, j = 0;


	while (r0 <= r1&&c0 <= c1)
	{
		i = r0,j = c0;

		while (j <= c1) {
			res[i][j] = count++;
			j++;
		}
		i = r0 + 1,j = c1;
		while (i <= r1) {

			res[i][j] = count++;
			i++;
		}
		i = r1, j = c1-1;
		while (j >= c0)
		{
			res[i][j] = count++;
			j--;
		}
		i = r1-1, j = c0;
		while (i >= r0+1)
		{
			res[i][j] = count++;
			i--;
		}

		r0++, c0++;
		r1--, c1--;

	}

	return res;

}



int main()
{


	getchar();
	return 0;
}


