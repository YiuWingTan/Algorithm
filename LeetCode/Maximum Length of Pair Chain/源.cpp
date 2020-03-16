#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> paird;

//进行交换
void change(int i, int j)
{
	int n, m;
	n = paird[i][0];
	m = paird[i][1];
	paird[i][0] = paird[j][0];
	paird[i][1] = paird[j][1];
	paird[j][0] = n;
	paird[j][1] = m;
}

int compare(int i,int j)
{
	return paird[i][0] - paird[j][0];
}

//快速排序
void QuickSort(int i,int j)
{
	if (i >= j) return;
	int lo = i+1;
	int hi = j;
	int k = i;
	int mark = 0;
	while (lo<=hi)
	{
		mark = compare(k,lo);
		if (mark > 0) { change(k++, lo++); }
		else if (mark < 0) { change(lo, hi--); }
		else { lo++; }
	}

	QuickSort(i,k);
	QuickSort(k+1,j);
 }

int findLongestChain(vector<vector<int>>& pairs) {

	int n = pairs.size();
	paird = pairs;
	QuickSort(0, n - 1);
	int tail = paird[0][1];
	int num = 1;
	int head = paird[0][0];
	for (int i = 0; i < n; i++)
	{
		cout << "[" << paird[i][0] << "," << paird[i][1]<<"]"<<endl;
		if (tail < paird[i][0])
			num++;
		if (paird[i][1] < tail)
		{
			
			head = paird[i][0];
			tail = (paird[i][1]);
		}
	}

	return num;
}
int main()
{
	vector<vector<int>> p{
		{3,4},
		{2,3},
		{1,2}
	};

	cout<<"最大值是"<<findLongestChain(p)<<endl;

	getchar();
}