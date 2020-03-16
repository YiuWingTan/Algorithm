#include<iostream>
#include<vector>

using namespace std;


int getMinCount(vector<vector<int>>&arr)
{
	int N = arr.size();
	if (N == 0 || N != arr[0].size()) {
		throw "�þ���ĸ�ʽ����ȷ";
		return INT_MAX;
	}

	vector<int> a;
	a.resize(N,-1);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1) 
				a[i] = j;
		}
	}

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		int pos = -1;

		for (int j = i; j < N; j++)
		{
			if (i>=a[j])
			{
				pos = j;
				break;
			}
		}
		if (pos == -1) {
			throw "�þ���ĸ�ʽ����ȷ";
			return INT_MAX;
		}

		for (int k = pos; k > i; k--)
		{
			swap(arr[k],arr[k-1]);
			swap(a[k],a[k-1]);
			sum++;
		}
	}
	return sum;
}

void text1()
{
	vector<vector<int>> arr
	{
		{1,0},
		{1,1}
	};

	cout << "��С�Ľ�������Ϊ " << getMinCount(arr) << endl;
}

void text2()
{
	vector<vector<int>> arr
	{
		{ 0,0,1 },
		{ 1,0,0 },
		{ 0,1,0 }
	};

	cout << "��С�Ľ�������Ϊ " << getMinCount(arr) << endl;
}

void text3()
{
	vector<vector<int>> arr
	{
		{ 1,1,1,0 },
		{ 1,1,0,0 },
		{ 1,1,0,0 },
		{ 1,0,0,0 }
	};

	cout << "��С�Ľ�������Ϊ " << getMinCount(arr) << endl;
}



int main()
{
	text1();
	text2();
	text3();

	getchar();
	return 0;
}
