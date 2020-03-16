
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int getIndex(char c)
{
	switch (c)
	{
	case '<':
		return 0;
	case '(':
		return 1;
	case '[':
		return 2;
	case '{':
		return 3;
	}

	return -1;
}

int main()
{
	int N;
	string str;
	cin >> N;

	while (N > 0)
	{
		stack<char> st;
		cin >> str;

		bool result = true;

		for (int i = 0; i < str.size()&&result; i++)
		{
			if (str[i] == '[' || str[i] == '{' || str[i] == '('||str[i] == '<')
			{
				int pre, cur;
				cur = getIndex(str[i]);
				pre = st.empty() ? 4 : getIndex(st.top());

				if (pre >= cur) st.push(str[i]);
				else result = false;
			}
			else
			{
				if (st.empty()) result = false;
				else
				{
					if (str[i] == ')') result = st.top() == '(';
					else if (str[i] == ']') result = st.top() == '[';
					else if (str[i] == '>') result = st.top() == '<';
					else if (str[i] == '}') result = st.top() == '{';

					st.pop();
				}
			}
		}

		if (result&&st.empty())
			cout << "YES\n";
		else cout << "NO\n";

		N--;
	}



	return 0;
}

