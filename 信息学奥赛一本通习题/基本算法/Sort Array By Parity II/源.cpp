#include<iostream>
#include<vector>
using namespace std;


/*
题意
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.


-方法 - 双指针法

*/


vector<int> sortArrayByParityII(vector<int>& A)
{
	int i = 0, j = 1;


	while (i < A.size() && j < A.size())
	{
		while (i < A.size() && A[i] % 2 == 0) i += 2;
		while (j < A.size() && A[j]%2 != 0)j += 2;

		if (i < A.size() && j < A.size()) swap(A[i],A[j]);
	}

	return A;
}

int main()
{
	vector<int> A = { 3,1,2,4 };
	vector<int> arr = sortArrayByParityII(A);


	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	getchar();
	return 0;
}