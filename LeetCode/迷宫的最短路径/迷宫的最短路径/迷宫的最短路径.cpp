#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct Node
{
	int i = -1;
	int j = -1;

	Node(int _i,int _j)
	{
		i = _i;
		j = _j;
	}

	Node()
	{

	}
};
inline bool constrain(int k,int lo,int hi)
{
	if (k >= lo&&k <= hi) return true;
	return false;
}
int main()
{
	int n, m;
	queue<Node> q;
	cin >> n;
	cin >> m;
	Node **map = new Node*[n];
	string *str = new string[n];
	Node start,end;

	for (int i = 0; i < n; i++)
		map[i] = new Node[m];
	
	getchar();

	for (int i = 0; i < n; i++)
	{
		getline(cin,str[i]);

	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//		cout << str[i][j]<<" ";
	//	cout << endl;
	//}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] == 'S')
			{
				Node start(i,j);
				q.push(start);
				break;
			}
		}
	}

	while (!q.empty())
	{
		Node nq = q.front();
		str[nq.i][nq.j] = '@';
		q.pop();

		if (constrain(nq.i + 1, 0, n - 1) && (str[nq.i + 1][nq.j] == '.'|| str[nq.i + 1][nq.j] == 'G'))
		{
			Node nd(nq.i+1,nq.j);
			q.push(nd);
			map[nd.i][nd.j] = nq;
			if (str[nq.i + 1][nq.j] == 'G') {
				end = nd;
				break;
			}
		}
		if (constrain(nq.i - 1, 0, n - 1) && (str[nq.i - 1][nq.j] == '.'|| str[nq.i - 1][nq.j] == 'G'))
		{
			Node nd(nq.i - 1, nq.j);
			q.push(nd);
			map[nd.i][nd.j] = nq;
			if (str[nq.i - 1][nq.j] == 'G') {
				end = nd;
				break;
			}
		}
		if (constrain(nq.j + 1, 0, m - 1) && (str[nq.i][nq.j + 1] == '.'|| str[nq.i][nq.j + 1]=='G'))
		{
			Node nd(nq.i, nq.j+1);
			q.push(nd);
			map[nd.i][nd.j] = nq;
			if (str[nq.i][nq.j+1] == 'G') {
				end = nd;
				break;
			}
		}
		if (constrain(nq.j - 1, 0, m - 1) && (str[nq.i][nq.j - 1] == '.'|| str[nq.i][nq.j - 1] == 'G'))
		{
			Node nd(nq.i, nq.j-1);
			q.push(nd);
			map[nd.i][nd.j] = nq;
			if (str[nq.i][nq.j-1] == 'G') {
				end = nd;
				break;
			}
		}
	}
	int num = 0;
	while (end.i != -1)
	{
		num++;

		end = map[end.i][end.j];
	}
	cout << "²½ÊýÎª£º" << num - 1<<endl;
	system("pause");
	getchar();
    return 0;
}

