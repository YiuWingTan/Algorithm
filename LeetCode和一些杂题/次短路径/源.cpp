#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<functional>
using namespace std;

struct Edge
{
	int from;
	int to;
	int cost;
};

void swap(int &a,int &b)
{
	int mid = a;
	a = b;
	b = mid;
}
void readGraph(const string &src,vector<vector<Edge>> &in_edge)
{
	ifstream inputStream;
	inputStream.open(src.c_str(),ios::in);

	if (!inputStream.is_open())
	{
		//打开文件失败
		cout << "打开文件失败\n";
		return;
	}

	int n = 0;
	int from = 0, to = 0,cost =0;
	inputStream >> n;
	in_edge.clear();
	in_edge.resize(n+1);

	while (inputStream >> from >> to >> cost)
	{
		if (from > n || to > n) { cout << "文件中的顶点数据有误" << endl;in_edge.clear(); return; }
		in_edge[from].push_back({from,to,cost});
	}

	for (int i = 1; i < in_edge.size(); i++)
	{
		cout << i << " :  ";
		for (int j = 0; j < in_edge[i].size(); j++)
		{
			cout << i << "->"<<in_edge[i][j].to<<"  ";
		}
		cout << endl;
	}
}
struct  P
{
	int first;//表示路径的大小
	int second;//表示顶点
};
bool operator>(const P&a, const P&b) { return a.first > b.first; }
int getSecondPathValue(vector<vector<Edge>>&edges,int source,int target)
{
	if (source <= 0 || source >= edges.size()) return INT_MAX;

	vector<int> cost ;//表示最短路径
	cost.resize(edges.size()+1,INT_MAX);
	vector<int> dcost;//表示次短路径
	dcost.resize(edges.size()+1,INT_MAX);
	cost[source] = 0;
	dcost[source] = 0;
 	priority_queue<P, vector<P>, greater<P>> que;
	que.push({0,1});

	while (!que.empty())
	{
		int val = que.top().first;
		int from = que.top().second;
		que.pop();

		if (val > dcost[from]) continue;
		int k = edges[from].size();
		for (int i = 0; i < edges[from].size(); i++)
		{
			int n = val + edges[from][i].cost;
			int to = edges[from][i].to;
			if (n < cost[to])
			{
				swap(cost[to],n);//关键交换
				que.push({ cost[to],to });
			}
			if (n < dcost[to]) {
				dcost[to] = n;
				que.push({ n,to });
			}
		}

	}

	return dcost[target] == INT_MAX?cost[target]:dcost[target];
}


//功能测试
void text1()
{
	string src = "Graph.txt";
	int source = 1;
	int target = 4;//待定
	vector<vector<Edge>> edges;
	readGraph(src, edges);
	target = edges.size() - 1;

	cout <<source<<" 到 "<<target << " 的次短路径是:"<<getSecondPathValue(edges,source,target)<<endl<<endl;
}

//边界测试
void text2()
{
	string src = "SpecialGraph.txt";
	int source = 1;
	int target = 4;//待定
	vector<vector<Edge>> edges;
	readGraph(src, edges);
	target = edges.size() - 1;

	cout << source << " 到 " << target << " 的次短路径是:" << getSecondPathValue(edges, source, target) << endl << endl;
}
void text3()
{
	string src = "SpecialGraph2.txt";
	int source = 1;
	int target = 4;//待定
	vector<vector<Edge>> edges;
	readGraph(src, edges);
	target = edges.size() - 1;

	cout << source << " 到 " << target << " 的次短路径是:" << getSecondPathValue(edges, source, target) << endl << endl;
}

int main()
{
	text1();
	text2();
	text3();


	getchar();
	return 0;
}
