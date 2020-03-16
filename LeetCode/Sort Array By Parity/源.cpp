#include<iostream>
#include<vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {

	vector<int> even;
	vector<int> odd;

	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] % 2 == 0) even.push_back(A[i]);
		else odd.push_back(A[i]);
	}

	even.insert(even.end(), odd.begin(), odd.end());


	return even;
}


int main()
{

}