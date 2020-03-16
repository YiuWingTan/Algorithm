
/*
解决思路：
使用bfs和哈希。将生成出来的数进行标记然后使用规则生成下一个新的数并放到队列中

*/



#include<iostream>
#include<string>
#include<queue>

using namespace std;

bool _hash[2001];
int number[50];
int rule[50];

int main()
{
	int n,k;
	int count = 0;
	cin >> n >> k;

	for (int i = 0; i < k; i++) cin >> number[i]>>rule[i];

	queue<int> que;
	que.push(n);
	_hash[n] = true;


	while (!que.empty())
	{
		int num = que.front(); que.pop();
		int m = num;

		int step = 1;
		count++;
		while (m>0)
		{
			int t = m % 10;
			m /= 10;

			for(int i = 0;i<k;i++)
				if (t == number[i])
				{

					int total = num + (rule[i] - number[i])*step;

					if ((!_hash[total]))
					{

						que.push(total);
						_hash[total] = true;
					}

				}
			step *= 10;
		}

	}

	cout << count << endl;

	return 0;
}
