#include<iostream>
#include<vector>
#include<set>
using namespace std;

class UnionSet
{
private:
	vector<int> par;
	vector<int> rank;
	int num;//记录集合的数量
public:
	UnionSet(int n)
	{
		par.resize(n);
		rank.resize(n, 0);

		for (int i = 0; i < par.size(); i++)
		{
			par[i] = i;
		}

		num = n;
	}
	void Init(int n)
	{
		par.resize(n);
		rank.resize(n, 0);

		for (int i = 0; i < par.size(); i++)
		{
			par[i] = i;
		}
	}
	int Find(int x)
	{
		if (x < 0 || x >= par.size()) return x;
		return find(x);
	}
	bool Union(int x, int y)
	{
		if (x < 0 || x >= par.size()) return false;
		if (y < 0 || y >= par.size()) return false;

		un(x,y);

		return true;
	}
	bool isSame(int x, int y)
	{
		if (x < 0 || x >= par.size()) return false;
		if (y < 0 || y >= par.size()) return false;

		return find(x) == find(y);

	}
	int SetNumber() { return num; }

private:
	int find(int x)
	{
		if (par[x] == x) return x;

		return par[x] = find(par[x]);
	}
	void un(int x,int y) {
		int i = find(x);
		int j = find(y);

		if (i == j) return;
		num--;
		if (rank[i] > rank[j]) {
			par[j] = i;
		}
		else
		{
			par[i] = j;
			if (rank[i] == rank[j]) rank[j]++;
		}
	}

};

UnionSet uns(20000);
//解法二 并查集
int removeStones(vector<vector<int>>& stones)
{
	if (stones.size() <= 1) return 0;
	uns.Init(20000);


	for (int i = 0; i < stones.size(); i++)
		uns.Union(stones[i][0], stones[i][1] + 10000);

	set<int> s;

	for (int i = 0; i < stones.size(); i++)
		s.insert(uns.Find(stones[i][0]));

	return stones.size() - s.size();

}







//解法一 DFS
/*
vector<vector<int>> ans;
vector<bool> marked;
int num = 0;

void connect(int i,int j)
{
	ans[i].push_back(j);
	ans[j].push_back(i);
}

void dfs(int i)
{
	num++;
	for (auto const&x : ans[i])
	{
		if (!marked[x])
		{
			marked[x] = true;
			dfs(x);
		}
	}
}

int removeStones(vector<vector<int>>& stones) {

	if (stones.size() == 0||stones.size() == 1) return 0;

	ans.clear();
	marked.clear();
	ans.resize(stones.size());
	marked.resize(stones.size());

	
	for (int i = 0; i < stones.size(); i++)
	{
		for (int j = i+1;j < stones.size(); j++)
		{
			if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {

				connect(i,j);
				connect(j,i);
			}
		}
	}

	for (int i = 0; i < stones.size(); i++)
	{
		if (!marked[i])
		{
			marked[i] = true;
			num--;
			dfs(i);
		}
	}

	return num;
}
*/



int main()
{
	vector<vector<int>> arr = {
		{0,0},
	};
	cout<<removeStones(arr);

	getchar();
	return 0;
}
