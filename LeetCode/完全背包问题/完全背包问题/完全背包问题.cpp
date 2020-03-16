#include<iostream>
using namespace std;
struct Item
{
public:
	int w;
	int v;

	Item()
	{

	}

	Item(int _w, int _v)
	{
		w = _w;
		v = _v;
	}
};
int n, w;
int **best;
Item *items;


inline void solve()
{
	for (int i = 1; i <=n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (j < items[i].w)
			{
				//放不了一个
				best[i][j] = 0;
			}
			else
			{
				//能放得了一个或者是一个以上
				int max = best[i][j];
				for (int num = 0; j >= items[i].w*num; num++)
				{
					int m = best[i-1][j - items[i].w*num]+items[i].v*num;
					if (max < m)
						max = m;
				}

				best[i][j] = max;
			}
		}
	}
}

int main()
{
	cin >> n;
	cin >> w;
	items = new Item[n+1];
	best = new int*[n+1];


	for (int i = 0; i <=n; i++) {
		best[i] = new int[w+1];

		for (int j = 0; j <= w; j++)
		{
			best[i][j] = 0;
		}
	}
	
	for (int i = 1; i <=n; i++)
	{
		cout << "请输入第"<<i<<"个物品的数据 : ";
		cin >> items[i].w;
		cin >> items[i].v;
		cout << endl;
	}

	solve();

	cout << "最大价值是:"<<best[n][w]<<endl;

	system("pause");
    return 0;
}

