
/*
解决思路
使用bfs

*/

#include<iostream>
#include<queue>

using namespace std;

bool graph[101][101];
bool visit[101];

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int n, m;
		cin >> n >> m;
		graph[n][m] = true;
	}
	int count = 0;
	int num = 0;
	int maxNum=0;
	
	for (int i = 1; i <= n; i++)
	{
		if (visit[i]) continue;
		queue<int> que;
		count++;
		que.push(i);
		num = 1;
		visit[i] = true;
		while (!que.empty())
		{
			int from = que.front(); que.pop();
			
			for (int to = 1; to <= n; to++)
			{
				if (graph[from][to]&&!visit[to])
				{
					que.push(to);
					visit[to] = true;
					num++;
				}
			}
		}

		if (num > maxNum) maxNum = num;

	}


	cout << count<<" "<<maxNum<<endl;

	return 0;
}

