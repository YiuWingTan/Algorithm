
#include<iostream>
#include<string>
#include<vector>
using namespace std;



int main()
{
	vector<string> re;

	int n;
	cin >> n;


	for (int k = 0; k < n; k++)
	{
		string str;
		int m;
		cin >> str >> m;


		while(m>0)
		{
			int i = 0;
			while (i < str.size() && str[i] == '0')i++;

			int j = i+1;
			while (j < str.size()) {

				if (str[j] == '0') {
					j++;
					continue;
				}

				if (str[i] > str[j]) break;

				i = j;
				j++;

			}

			str[i] = '0';

			m--;
		}
		re.push_back(str);

	}


	for (int i = 0; i < re.size(); i++)
	{
		for (int j = 0; j < re[i].size(); j++)
		{
			if (re[i][j] != '0')
				cout << re[i][j];
		}
		cout << endl;
	}

	return 0;
}

