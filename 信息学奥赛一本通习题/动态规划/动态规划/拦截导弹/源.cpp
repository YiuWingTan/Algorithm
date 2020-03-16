
#include<iostream>
#include<stdio.h>
using namespace std;

int arr[1000];
int systems[1000];
int dp[1000][2];

int main()
{
	int N = 0,systemCount = 0;
	while (scanf("%d", &arr[N++]) != EOF );

	for (int i = 0; i < N; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = -1;
		
		int j = 0, min = 400000, minIndex = -1;
		for (; j < systemCount; j++) {

			if (systems[j] < min&&systems[j]>=arr[i])
			{
				min = systems[j];
				minIndex = j;
			}

		}
		if (minIndex != -1)
			systems[j] = arr[i];
		else
			systems[systemCount++] = arr[i];
	}

	for (int i = N - 2; i >= 0; i--) {

		int max = 0;
		int maxIndex = -1;

		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] >= arr[j] && dp[j][0] > max)
			{
				max = dp[j][0];
				maxIndex = j;
			}
		}

		dp[i][0] = max + 1;
		dp[i][1] = maxIndex;
	}


	//Ñ°ÕÒ×î³¤µÄ´®
	int maxIndex = 0,max = 0;
	for (int i = 0; i < N; i++)
		if (dp[i][0] > max)
		{
			maxIndex = i;
			max = dp[i][0];
		}
	cout <<dp[maxIndex][0]<<endl << systemCount+1 << endl;

	return 0;
}


