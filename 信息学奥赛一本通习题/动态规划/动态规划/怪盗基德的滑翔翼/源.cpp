
#include<vector>
#include<iostream>
using namespace std;

int a[1000];
int b[1000];
int dpa[1000];
int dpb[1000];
vector<int> result;


void slove()
{
	
	int N, tmp;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		a[i] = b[N - 1 - i] = tmp;
	}

	//初始化
	dpa[0] = 1;
	dpb[0] = 1;



	for (int i = 1; i < N; i++)
	{
		int tmp_maxb = 0, tmp_maxa = 0;
		dpa[i] = dpb[i] = 1;

		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] < a[i] && tmp_maxa < dpa[j]) tmp_maxa = dpa[j];
			if (b[j] < b[i] && tmp_maxb < dpb[j]) tmp_maxb = dpb[j];
		}
		dpa[i] += tmp_maxa;
		dpb[i] += tmp_maxb;
	}

	//选出最大值
	int max = 1;
	for (int i = 0; i < N; i++)
	{
		if (dpa[i] > max) max = dpa[i];
		if (dpb[i] > max) max = dpb[i];
	}


	result.push_back(max);

}


int main()
{
	int N;
	cin >> N;

	while (N > 0)
	{
		slove();
		N--;
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i]<<endl;


	return 0;

}





