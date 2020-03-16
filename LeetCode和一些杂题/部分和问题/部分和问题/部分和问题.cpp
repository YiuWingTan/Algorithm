#include<iostream>
#include<stack>
using namespace std;
int n, k;
stack<int> s;

inline bool solve(int a[],int sum,int key,int value)
{

	sum += value;
	
	if (sum == key) { return true; }

	static int i = -1;
	if (++i < n)
	{
		if (solve(a, sum, key, a[i])) { s.push(a[i]); i--; return true; }
		if (solve(a, sum, key, 0)) { return true; }
	}
	
	--i;
	return false;
}

int main()
{
	

	cin >> n;
	cin >> k;
	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (solve(a, 0, k, 0))
	{
		cout << "Yes "<<k<<" = ";

		while (!s.empty())
		{
			cout<<s.top()<<" ";
			s.pop();
		}

		cout << endl;
	}
	else cout << "No";
	cout << endl;

	system("pause");

    return 0;
}

