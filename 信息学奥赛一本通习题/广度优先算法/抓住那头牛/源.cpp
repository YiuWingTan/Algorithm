
#include<iostream>
#include<queue>
using namespace std;

bool road[100001];

int bfs(int n,int tar)
{
	int num = 1;
	int count = 1;
	queue<int> que;
	road[n] = true;
	que.push(n);

	while (!que.empty())
	{
		int p = que.front(); que.pop();
		for (int i = 0; i < 3; i++)
		{
			int offset;
			if (i == 0) offset = 1;
			else if (i == 1) offset = -1;
			else offset = p;

			int np = offset + p;

			if (np < 0 || np>100000||road[np]) continue;

			if (np == tar) return count;

			road[np] = true;
			que.push(np);
		}

		if (--num == 0)
		{
			num = que.size();
			count++;
		}

	}
	return -1;
}


int main()
{
	int N, M;
	cin >> N >> M;

	cout << bfs(N,M)<<endl;



	return 0;
}



