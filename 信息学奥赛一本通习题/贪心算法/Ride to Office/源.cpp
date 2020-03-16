

#include<iostream>
#include<vector>
using namespace std;

vector<int> re;

int v[10000];
int t[10000];

int main()
{

	int n;
	
	while (cin >> n)
	{
		if (n == 0) break;
		float mint = 1000000;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i] >> t[i];

			if (t[i] < 0) continue;

			float time = 4.5f / (float)v[i] * 3600 + (float)t[i];

			if (time < mint) mint = time;

		}

		float d = mint - (int)mint;
		if(d>0)
		re.push_back(mint+1);
		else re.push_back(mint);

	}



	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i]<<endl;
	}


	return 0;
}

