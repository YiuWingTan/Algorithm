
/*
使用三个队列，一个保存2x+1，一个保存3x+1，还有一个保存全部
注意队列中相同数据的处理
*/


#include<iostream>
#include<queue>

using namespace std;



int main()
{
	int a, n;
	
	while (cin >> a >> n)
	{

		queue<int> q1,q2,q3;
		int count = 1;

		q1.push(a);
		
		while (q1.size()<n)
		{
			int k = q1.back();
			q2.push(2*k+1);
			q3.push(3*k+1);

			if (q2.empty())
			{
				q1.push(q3.front()); q3.pop();
			}
			else if (q3.empty())
			{
				q1.push(q2.front()); q2.pop();
			}
			else if (q2.front() > q3.front())
			{
				q1.push(q3.front());
				q3.pop();
			}
			else if(q2.front()<q3.front())
			{
				q1.push(q2.front());
				q2.pop();
			}
			else
			{
				q1.push(q2.front());
				q2.pop();
				q3.pop();
			}
			count += 2;
		}


		
		cout << q1.back()<<endl;
	}
	

	return 0;
}

