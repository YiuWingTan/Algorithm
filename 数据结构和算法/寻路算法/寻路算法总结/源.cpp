#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
#include<queue>
#include<functional>
using namespace std;

int min(int x, int y)
{
	return x > y ? y : x;
}

//读取文件并创建边的集合
vector<vector<int>> readFile(const string &src)
{
	int n;
	vector<vector<int>> result;
	ifstream infile;
	infile.open(src.c_str(), ios::in);
	assert(infile.is_open());

	infile >> n;
	result.resize(n + 1);
	for (int i = 0; i < n + 1; i++) result[i].resize(n + 1, INT_MAX);

	int to, from, cost;
	to = from = cost = 0;
	while (infile >> from >> to >> cost) result[from][to] = cost;


	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
			if (result[i][j] == INT_MAX) cout << i << " " << j << " " << "#" << " " << endl;
			else cout << i << " " << j << " " << result[i][j] << " " << endl;
	}
	cout << endl << endl;
	return result;
}


//floydWarshall算法
vector<vector<int>> floydWarshall(vector<vector<int>>&road)
{
	auto path = road;
	for (int k = 1; k < road.size(); k++)
	{
		for (int i = 1; i < road.size(); i++)
		{
			for (int j = 1; j < road.size(); j++)
				if (path[i][k] != INT_MAX&&path[k][j] != INT_MAX)
					path[i][j] = min(path[i][k] + path[k][j], path[i][j]);
		}
	}

	return path;
}

void textFloydWarshall(vector<vector<int>> &road)
{

	auto path = floydWarshall(road);


	for (int i = 1; i < path.size(); i++)
	{
		for (int j = 1; j < path.size(); j++)
			if (path[i][j] == INT_MAX) cout << i << " " << j << " " << "#" << " " << endl;
			else cout << i << " " << j << " " << path[i][j] << " " << endl;
	}
	cout << endl;
}


//bellmanFord算法
vector<int> bellmanFord(vector<vector<int>>&road, int source)
{
	int n = road.size() - 1;
	if (n == 0 || n < source || source == 0) return{};
	vector<vector<int>> result;

	vector<int> cost;
	cost.resize(n + 1, INT_MAX);
	cost[source] = 0;

	while (true)
	{
		bool update = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (cost[i] != INT_MAX&&road[i][j] != INT_MAX && (cost[j] > cost[i] + road[i][j]))
				{
					cost[j] = cost[i] + road[i][j];
					update = true;
				}
			}
		}
		if (!update) break;
	}


	return cost;
}

void textBellmanFord(vector<vector<int>>&road)
{
	int source = 1;
	auto path = bellmanFord(road,source);

	cout << "顶点" << source << "到其余顶点的最短路径是" << endl;


	for (int i = 1; i < path.size(); i++)
	{
		cout << source << "->" << i << "  " << path[i]<<endl;
	}
	cout << endl<<endl;
}


typedef pair<int, int> P;//前一个值代表点，后一个值代表距离

vector<int> dijkstra(vector<vector<int>>&road,int source)
{
	int n = road.size() - 1;
	if (n == 0 || n < source || source == 0) return{};
	vector<int> cost;
	cost.resize(n + 1, INT_MAX);
	cost[source] = 0;


	priority_queue<P, vector<P>, greater<P>> que;
	que.push({source,0});

	while (!que.empty())
	{
		P p = que.top(); que.pop();
		if (cost[p.first] < p.second) continue;

		for (int i = 1; i <= n; i++)
		{
			if (road[p.first][i] == INT_MAX) continue;

			if (road[p.first][i] + cost[p.first] < cost[i]) {
				cost[i] = road[p.first][i] + cost[p.first];
				que.push({i,cost[i]});
			}
		}
	}


	return cost;
 }

void textDijkstra(vector<vector<int>>&road)
{
	int source = 1;
	auto path = dijkstra(road,source);

	cout << "顶点" << source << "到其余顶点的最短路径是" << endl;


	for (int i = 1; i < path.size(); i++)
	{
		cout << source << "->" << i << "  " << path[i] << endl;
	}
	cout << endl << endl;
}

int main()
{
	string src = "road.txt";
	auto road = readFile(src);

	textFloydWarshall(road);

	textBellmanFord(road);

	textDijkstra(road);

	getchar();
	return 0;
}
