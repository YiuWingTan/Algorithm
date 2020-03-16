
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


int main()
{
	int n;

	vector<float> re;

	while (cin >> n)
	{
		float sum = 0;
		float max = -1000;
		float val;
		for (int i = 0; i < n; i++)
		{

			cin >> val;
			if (val > max) max = val;
			sum += val;
		}

		if (max > sum - max)
		{

			re.push_back(sum - max);
		}
		else
		{
			re.push_back(sum / 2.0f);
		}


	}

	for (int i = 0; i < re.size(); i++)
		printf("%.1f\n",re[i]);

	return 0;
}


