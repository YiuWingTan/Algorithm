
/*
����һ��ͼȻ��ʹ��bfs

ע��ͼ������ͼ

*/
#include<iostream>
#include<queue>

using namespace std;

int graph[201][201];
int arr[201];
bool visited[201];
int oper[] = { 1,-1 };
int path[201];

int main()
{
	int n,start,end;
	cin >> n >> start >> end;

	for (int i = 1; i <=n; i++) cin >> arr[i];


	if (start == end)
	{
		cout << "0" << endl;
		return 0;
	}


	for (int i = 1; i <= n; i++)
	{
		int s = i;
		int e = i;
		for (int j = 0; j < 2; j++)
		{
			e = i + oper[j] * arr[i];

			//�����յ��λ�÷��Ϸ�Χ
			if (e > 0 && e <= n)
			{
				graph[s][e] = 1;
			}

		}
	}
	queue<int> que;
	que.push(start);
	int count = 0;
	bool isFind = false;

	while (!que.empty()&&!isFind)
	{
		int s = que.front(); que.pop();

		if (s == end) {
			isFind = true;
			break;
		}

		for (int i = 1; i <= n; i++)
		{
			if (graph[s][i] == 1 && !visited[i]&&i!=s)
			{
				//��һ��s��һ�����������Ҹõ㾭����ʱ��
				path[i] = s;
				que.push(i);
				visited[i] = true;
				
				
			}
		}

	
	}

	if(!isFind)
	cout << "-1" << endl;
	else
	{
		while (end != start)
		{
			end = path[end];
			count++;
		}
		cout << count << endl;
	}

	return 0;
}

