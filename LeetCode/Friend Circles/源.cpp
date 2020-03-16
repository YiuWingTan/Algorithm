#include<iostream>
#include<vector>

using namespace std;

class UnionSet
{
private:
	vector<int> par;
	vector<int> rank;
public:
	UnionSet(int n)
	{
		par.resize(n,-1);
		rank.resize(n, 0);
	}

	UnionSet() {}

	void Init(int n)
	{
		par.resize(n, -1);
		rank.resize(n, 0);
	}

	int Find(int n)
	{
		if (par.size() <= n || n<0) return n;

		if (par[n] == -1) 
			return n;

		par[n] = Find(par[n]);

		return par[n];
	}

	bool Union(int m, int n)
	{
		if (m >= par.size() || n >= par.size()) return false;
		if (m < 0 || n < 0) return false;

		int x = Find(m);
		int y = Find(n);

		if (x == y) return true;

		if (rank[x] > rank[y]) {
			par[y] = x;
		}
		else {
			par[x] = y;
			if (par[x] == par[y]) {
				rank[y]++;
			}
		}
		return true;
	}

	bool Same(int x, int y)
	{
		if (x >= par.size() || x < 0) return x == y;
		if (y >= par.size() || y < 0) return x == y;

		return Find(x) == Find(y);
	}

	int SetNumber()
	{
		int num = 0;
		for (int i = 0; i < par.size(); i++)
		{
			
			if (par[i] == -1) num++;
		}
		return num;
	}
};

int findCircleNum(vector<vector<int>>& M) {

	UnionSet uns;
	uns.Init(M.size());

	for (int i = 0; i < M.size(); i++)
	{
		for (int j = 0; j < M.size(); j++)
		{
			if(M[i][j] == 1)
			uns.Union(i,j);
		}
	}

	return uns.SetNumber();

}

int main()
{
	vector<vector<int>>arr = 
	{
		{ 1,0,0 },
		{ 0,1,0 },
		{ 0,0,1 }
	};

	cout << findCircleNum(arr);

	getchar();
	return 0;
}

