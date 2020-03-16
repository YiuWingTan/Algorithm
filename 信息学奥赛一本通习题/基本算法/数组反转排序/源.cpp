#include<iostream>
#include<vector>

using namespace std;


void filp(vector<int>&list,int k)
{
	int lo = 0, hi = k;
	while (lo < hi)
	{
		swap(list[lo++],list[hi--]);
	}
}


vector<int> pancakeSort(vector<int> A) {


	vector<int> result;

	
	int min;//当前最小值的位置
	int premin = -1;

	
	return result;
}

int main()
{
	pancakeSort({3,2,4,1});

	getchar();
	return 0;
}

