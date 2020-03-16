



#include<iostream>
using namespace std;

//‘À––≥¨ ±
int func(int n)
{
	if (n <=1) return 1;

	int count = 0;

	for (int i = 1; i <= n / 2; i++)
	{
		count += func(i);
	}
	return count+1;

}
#include<iostream>
using namespace std;

int dp[1001];



int main()
{

	int n;
	cin >> n;

	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i / 2; j++)
		{
			dp[i] += dp[j];
		}
		dp[i]++;
	}


	cout << dp[n]<<endl;
	return 0;
}


