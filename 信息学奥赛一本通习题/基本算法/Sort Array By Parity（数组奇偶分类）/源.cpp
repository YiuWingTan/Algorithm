#include<iostream>
#include<vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {

	if (A.size() <= 1) return A;
	
	int k = 0;

	for (int i = 0; i < A.size(); i++)
	{
		if (!(A[i]&1))
		{
			swap(A[k++], A[i]);

		}
	}


	return A;
}

int main()
{
	vector<int> A = { 3,1,2,4 };
	vector<int> arr = sortArrayByParity(A);


	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i]<<" ";
	}

	getchar();
	return 0;
}








