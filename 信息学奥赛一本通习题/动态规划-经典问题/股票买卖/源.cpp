
/*

╩ЁрилБд©спнС

*/

#include<iostream>
#include<algorithm>
using namespace std;

int a[100001];

int main()
{
	int N;
	cin >> N;

	while (N > 0)
	{
		int n;
		int buy, sell;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];

		buy = -a[1];
		sell = 0;

		for (int i = 2; i <= n; i++)
		{
			sell = max(sell,buy+a[i]);
			buy = max(buy,sell - a[i]);

		}

		cout << sell << endl;

		--N;
	}


	return 0;
}
