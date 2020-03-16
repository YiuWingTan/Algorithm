#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<int> edges[3600];
bool marked[3600];

void Init()
{
	for (int i = 0; i < 3600; i++)
	{
		edges[i].clear();
		marked[i] = false;
	}
	
}


/*
 解法一使用深度优先搜索
 也可以使用并查集来进行求解
*/
void dfs(int i)
{
	for (auto const& x : edges[i])
	{
		if (!marked[x])
		{
			marked[x] = true;
			dfs(x);
		}
	}
}

void connect(int i,int j)
{
	edges[i].push_back(j);
	edges[j].push_back(i);
}

int regionsBySlashes(vector<string>& grid) {

	Init();
	int num = 0;
	int N = grid.size();
	for (int i = 0; i < N; i++)
	{
		
		for (int j = 0; j < N; j++)
		{
			int n = 4*(i*N+j);
			//将相邻的两个三角形之间进行链接
			if (j < N - 1)
			{
				int n1 = 4*(i*N+j+1);
				connect(n+2,n1);//将左右邻接的两个不同矩形的边界三角形进行链接
			}
			if (i < N - 1)
			{
				int n1 = 4 * ((i+1)*N+j);
				connect(n+1,n1+3);//将上下邻接的两个不同矩形的边界三角形进行链接
			}
		}
	}


	//进行障碍判断
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n = 4*(i*N+j);
			if (grid[i][j] == '\\')
			{
				connect(n, n + 1);
				connect(n + 2, n + 3);
				
			}
			else if (grid[i][j] == '/')
			{
				
				
				connect(n, n + 3);
				connect(n + 1, n + 2);
			}
			else if (grid[i][j] == ' ') {
				connect(n, n + 3);
				connect(n + 3, n + 2);
				connect(n + 2, n + 1);
				connect(n + 1, n);
			}
			
		}
	}

	for (int i = 0; i < 4 * N*N; i++)
	{
		if (!marked[i])
		{
			marked[i] = true;
			dfs(i);
			num++;
		}
	}
	return num;
}

int main()
{
	
	vector<string> arr =
	{
		" /",
		"  "
	};

	cout<<regionsBySlashes(arr)<<endl;

	getchar();
	return 0;
}



