#include<iostream>
#include<vector>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {

	int pre = 0;
	int count = 0;

	for (int i = 2; i < A.size(); i++)
	{
		if (A[i - 1] - A[i - 2] == A[i] - A[i - 1])
		{
			//可以形成一个数列
			pre = pre + 1;
			count += pre;
		}

	}

	return count;
}


int main()
{

	getchar();
	return 0;
}

