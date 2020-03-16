

#include<iostream>
using namespace std;

int N, W;
int total = 0;
struct Item
{
	int p;
	int v;
	int n;
};

int max(int a,int b)
{
	return a > b ? a : b;
}

Item items[1000];
Item subItems[10000];
int dp[10000];
int counts[10000];

//朴素解法-时间复杂度是O(N*W*N)
void NormalSlove()
{
	memset(dp,0x00,sizeof(int)*(W+1));
	for (int i = 1; i <= N; i++)
	{
		for (int j = W; j >= items[i].p; j--)
		{
			for (int k = 0; k <= items[i].n; k++)
			{
				if (j - k * items[i].p >= 0)
				{
					if (dp[j - k * items[i].p] + items[i].v*k > dp[j])
					{
						dp[j] = dp[j - k * items[i].p] + items[i].v*k;
						counts[j] = k;

					}
				}
				else break;
			}
		}

	}
	cout << dp[W] << endl;
}

//二进制解法-时间复杂度是O(N*logN之和)
void BinarySlove()
{
	//找出要将物品分解为多少个子物品
	memset(dp, 0x00, sizeof(int)*(W + 1));
	for (int i = 1; i < total; i++)
	{
		for (int j = W; j >= subItems[i].p; --j)
		{
			dp[j] = max(dp[j],dp[j-subItems[i].p]+subItems[i].v);
		}
	}
	cout << dp[W]<<endl;
}

int main()
{
	
	cin >> N >> W;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> items[i].p >> items[i].v >> items[i].n;

		//计算每一个物品的子物品的系数
		total++;
		int n = items[i].n;
		int t = 1;
		while (t <= n) {
			subItems[total].p = items[i].p*t;
			subItems[total].v = items[i].v*t;
			total++;
			n -= t;
			t *= 2;
		}
		subItems[total].p = n*items[i].p;
		subItems[total].v = n*items[i].v;
		
	}

	//NormalSlove();
	BinarySlove();
	
	return 0;
}

