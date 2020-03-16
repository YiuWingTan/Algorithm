
#include<iostream>
#include<stack>
#include<string>
using namespace std;



int main()
{
	stack<int> st;
	st.push(1);
	bool result = true;
	int N,v,j = 1;
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> v;

		while (j <= v)
		{
			st.push(j++);
		}

		if (st.top() == v) st.pop();
		else {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}


