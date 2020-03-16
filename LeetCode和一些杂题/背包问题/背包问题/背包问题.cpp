#include<iostream>
using namespace std;
struct Item
{

	int w = 0;
	int v = 0;

	Item()
	{

	}

	Item(int _w, int _v)
	{
		w = _w;

		v = _v;
	}
};
int **best;
Item *items;
int n;
int w;

inline int max(int i,int j)
{
	return i > j ? i : j;
}
inline int solve(int i,int s)
{
	int res= 0;
	
	if (i == n) {
		return 0;
	}
	else if(best[i][s]!=-1)
	{
		cout << "�м���\n";
		return best[i][s];
	}
	else if(s<items[i].w)
	{
		res = solve(i+1,s);
	}
	else
	{
		res = max(solve(i + 1, s - items[i].w) + items[i].v, solve(i + 1, s));
	}
	best[i][s] = res;
	
	return res;
}

///��̬�滮�Ľⷨ
inline void solve()
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= w; j++)
		{
			if (i+1 < n)
			{
				if (items[i].w > j)
					best[i][j] = best[i + 1][j];
				else
					best[i][j] = max(best[i + 1][j], best[i + 1][j - items[i].w] + items[i].v);
			}
			else
			{
				if (items[i].w > j) best[i][j] = 0;
				else best[i][j] = items[i].v;
			}
		}

	}
}

int main()
{
	cin >> n;
	cin >> w;
	items = new Item[n];
	best = new int*[n];

	for (int i = 0; i < n; i++)
	{
		cout << "�������"<<i+1<<"��Ʒ����Ϣ ";
		cin>>items[i].w;
		cin >> items[i].v;
		best[i] = new int[w+1];

		for (int j = 0; j <=w; j++)
		{
			best[i][j] = -1;
		}
	}
	
	
	//cout << "����ֵΪ:"<<solve(0,w)<<endl;
	solve();
	
	cout << "ʹ�ö�̬�滮��ĵĽ���:"<<best[0][w];

	system("pause");

    return 0;
}

