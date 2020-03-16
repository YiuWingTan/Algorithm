
#include<iostream>
#include<stack>

using namespace std;

int main()
{
	bool result = true;
	char c;
	stack<char> st;

	while (cin >> c&&result)
	{
		if (c == '@') break;

		if (c == '(') st.push(c);
		else if (c == ')')
		{
			if (st.size() > 0) st.pop();
			else result = false;
		}

	}


	if (result&&st.size() == 0) cout << "YES\n";
	else cout << "NO\n";


	return 0;
}