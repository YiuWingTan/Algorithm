
#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int a, b, n;
	cin >> a >> b >> n;

	queue<int> q1;
	queue<int> q2;

	for (int i = 1; i <= a; i++) q1.push(i);
	for (int i = 1; i <= b; i++) q2.push(i);

	for (int i = 0; i < n; i++)
	{
		cout << q1.front() << " " << q2.front()<<endl;
		q1.push(q1.front()); q1.pop();
		q2.push(q2.front()); q2.pop();
	}


	return 0;
}


