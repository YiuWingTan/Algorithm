/*
难度 简单  主题 栈
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool isValid(string s) {

	
	stack<char> st;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
		{
			st.push(s[i]);
			continue;
		}
		else if (st.empty()) return false;
		else if (s[i] == ']'&&st.top() != '[') return false;
		else if (s[i] == '}'&&st.top() != '{') return false;
		else if (s[i] == ')'&&st.top() != '(') return false;
		st.pop();
	}

	return st.empty();
}


int main()
{
	getchar();
	return 0;
}