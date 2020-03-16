#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<functional>
#include <algorithm>
#include"Union.h"
using namespace std;

struct Edge
{
	int from;
	int to;
	int cost;
};

void swap(int &a, int &b)
{
	int mid = a;
	a = b;
	b = mid;
}
void readGraph(const string &src, vector<vector<Edge>> &in_edge)
{
	ifstream inputStream;
	inputStream.open(src.c_str(), ios::in);

	if (!inputStream.is_open())
	{
		//打开文件失败
		cout << "打开文件失败\n";
		return;
	}

	int n = 0;
	int from = 0, to = 0, cost = 0;
	inputStream >> n;
	in_edge.clear();
	in_edge.resize(n + 1);

	while (inputStream >> from >> to >> cost)
	{
		if (from > n || to > n) { cout << "文件中的顶点数据有误" << endl; in_edge.clear(); return; }
		in_edge[from].push_back({ from,to,-cost });
	}

	for (int i = 1; i < in_edge.size(); i++)
	{
		cout << i << " :  ";
		for (int j = 0; j < in_edge[i].size(); j++)
		{
			cout << i << "->" << in_edge[i][j].to << "  ";
		}
		cout << endl;
	}
}
struct P { int index; int val; };
bool operator>(const P&a,const P&b)
{
	return a.val > b.val;
}
//获取征兵的最小代价
int getMinPrice(vector<vector<Edge>> &edges)
{
	if (edges.size() <= 0) return 0;
	if (edges.size() == 1) return 10000;

	int n = edges.size();
	int result = 0;
	vector<int> minCost;
	vector<int> isset;
	priority_queue<P,vector<P>,greater<P>> que;
	minCost.resize(n,INT_MAX);
	isset.resize(n,false);
	
	for (int i = 1; i < edges.size(); i++)
	{
		if (isset[i]) continue;

		que.push({i,0});
		while (!que.empty())
		{
			auto p = que.top(); que.pop();
			if (isset[p.index]) continue;

			minCost[p.index] = p.val;
			isset[p.index] = true;
			result += p.val;
			for (int i = 0; i < edges[p.index].size(); i++)
			{
				int to = edges[p.index][i].to;
				if (!isset[to])
				{
					que.push({ to,edges[p.index][i].cost });
				}
			}
		}
	}

	
	return result;
}

bool less_edge(Edge &a,Edge &b)
{
	return a.cost < b.cost;
}

int Kruskal(vector<vector<Edge>> &edges)
{
	vector<Edge> sortEdges;
	int val = 0;
	int count =0;
	Union un(edges.size());
	for (int i = 0; i < edges.size(); i++)
	{
		for (int j = 0; j < edges[i].size(); j++)
		{
			sortEdges.push_back(edges[i][j]);
		}
	}
	sort(sortEdges.begin(),sortEdges.end(), less_edge);
	
	for (int i = 0; i < sortEdges.size()&&count<edges.size(); i++)
	{
		if (un.same(sortEdges[i].to,sortEdges[i].from)) continue;
		un.unite(sortEdges[i].to, sortEdges[i].from);
		val += sortEdges[i].cost;
		count++;
	}
	return val;
}

//功能测试
void text1()
{
	string src = "Graph.txt";
	int source = 1;
	int target = 4;//待定
	vector<vector<Edge>> edges;
	readGraph(src, edges);

	cout << "最小生成树是"<< (edges.size() - 1)*10000+Kruskal(edges)<<endl<<endl;
}

int main()
{
	text1();

	getchar();
	return 0;
}