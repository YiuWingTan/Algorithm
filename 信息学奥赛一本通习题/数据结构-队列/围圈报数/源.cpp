
#include<iostream>
#include<queue>

using namespace std;


int main()
{
	queue<int> que;
	int n, m,count = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) que.push(i);

	while (!que.empty())
	{
		count++;

		if (count != m)
		{
			que.push(que.front());
			que.pop();
			
		}
		else
		{
			cout << que.front()<<" ";
			que.pop();
			count = 0;
		}
		
	}

	cout << endl;

	return 0;
}



