
#include<iostream>
using namespace std;

struct Link
{
	int i, j;
};

Link link[501][501];
int dp[501][501];
int a[501];
int b[501];


int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> b[i];

	memset(link, 2147483647,sizeof(link));

	for (int i = 1; i <= N; i++)
	{
		int preMax = 0;
		for (int j = 1; j <= N; j++) {

			
		}
	}


	return 0;
}

