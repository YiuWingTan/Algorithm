#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main()
{
	stack<char> st;
	string str;
	cin >> str;

	bool result = true;

	for (int i = 0; i < str.size()&&result; i++)
	{
		if (str[i] == '[' || str[i] == '(')
			st.push(str[i]);
		else
		{
			if (str[i] == ')')
			{
				result = !st.empty()&&st.top() == '(';
			}
			else if (str[i] == ']')
			{
				result = !st.empty() && st.top() == '[';
			}
			if(!st.empty())
				st.pop();
		}
	}


	if (result&&st.empty())
	{
		cout << "OK\n";
	}
	else
	{
		cout << "Wrong\n";
	}

	return 0;
}
