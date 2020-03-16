#include"Union.h"
using namespace std;
Union::Union(int n)
{
	rank.resize(n,0);
	par.resize(n);
	for (int i = 0; i < n; i++) par[i] = i;
}

Union::~Union()
{
}

void Union::unite(int a, int b)
{
	int x = find(a);
	int y = find(b);

	if (x == y) return;

	if (rank[x] < rank[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}

int Union::find(int n)
{
	if (n<0 || n>par.size() - 1) { throw "No this element in the Union"; }
	if (par[n] == n) return n;
	return par[n] = find(par[n]);//跟新子节点的父节点的值
}

bool Union::same(int u, int v)
{
	return find(u) == find(v);
}
