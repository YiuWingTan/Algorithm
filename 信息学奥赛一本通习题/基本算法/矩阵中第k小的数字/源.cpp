#include<iostream>
#include<vector>

using namespace std;

/*
	使用切分
*/

int partion(vector<vector<int>>&m,int lo,int hi)
{
	int i = lo + 1;
	int j = hi;
	int k = lo;
	int n = m.size();

	while (i <= j)
	{
		int val = m[k / n][k%n] - m[i/n][i%n];

		if (val > 0) {
			swap(m[k / n][k%n], m[i / n][i%n]), k++, i++;
		}
		else if (val < 0)
		{
			swap(m[i / n][i%n],m[j/n][j%n]);
			j--;
		}
		else {
			i++;
		}
	}

	return j;
}


int kthSmallest(vector<vector<int>> &matrix, int k) {

	int len = matrix.size();
	len *= len;
	
	if (k <1 || k>len) return -1;

	int l = 0,r = len-1;

	while (l <= r)
	{
		int mid = partion(matrix,l,r);

		if (mid + 1 == k) return matrix[mid/matrix.size()][mid%matrix.size()];
		else if (mid + 1 < k)
		{
			l = mid+1;
		}
		else r = mid - 1;
	}

	return -1;
}


/*
	使用二分查找
*/



int main()
{
	vector<vector<int>> m = 
	{
		{1,5,9},
		{10,11,13},
		{12,13,15}
	};

	std::cout << kthSmallest(m,8) << endl;

	getchar();
	return 0;
}



