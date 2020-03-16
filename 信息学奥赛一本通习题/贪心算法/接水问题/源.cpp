
#include<iostream>
#include<vector>
using namespace std;

int w[10009];


int main()
{

	int n, m;

	cin >> n >> m;

	for (int i = 0; i <n; i++)
		cin >> w[i];

	vector<int> pack(m,0);
	int k = m>n?n:m,consume = 0;
	int min = 1000000;
	bool isEnd = false;
	//初始化
	for (int i = 0; i < k; i++)
	{
		if (min > w[i]) min = w[i];
		pack[i] = w[i];
	}


	while (!isEnd)
	{
		isEnd = true;
		int _min = 1000000;
		for (int i = 0; i < m; i++)
		{
			if (pack[i] == 0) continue;
			pack[i] -= min;
			if (pack[i] == 0&&k<n)
			{
				//更新下一个人进行打水
				pack[i] = w[k++];
			}
			isEnd = false;
			if (pack[i] < _min) _min = pack[i];
		}
		consume += min;
		min = _min;
	}

	cout << consume<<endl;

	return 0;
}

