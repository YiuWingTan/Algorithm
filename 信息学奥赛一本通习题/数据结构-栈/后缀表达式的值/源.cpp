
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	stack<long long> st;
	vector<char> oper;
	char c;
	long long value = 0;
	int result = 0;
	while((c = getchar())&& c != '@')
	{
		if (c >= '0'&&c <= '9')
		{
			//是数字
			value = value * 10 + (c - '0');
			continue;
		}
		else if(c!=' ')
		{
			//是运算符
			oper.push_back(c);
			continue;
		}
		st.push(value);
		value = 0;
	}

	

	long long a, b;
	for (int i = 0; i < oper.size(); i++)
	{
		switch (oper[i])
		{
		case '+':
			 a = st.top();st.pop();
			 b = st.top(); st.pop();
			st.push(a+b);
			
			break;
		case '-':
			 a = st.top(); st.pop();
			 b = st.top(); st.pop();
			st.push(b - a);
			
			break;
		case '*':
			 a = st.top(); st.pop();
			 b = st.top(); st.pop();
			st.push(a * b);
			
			break;
		case '/':
			 a = st.top(); st.pop();
			 b = st.top(); st.pop();
			st.push(b / a);
			
			break;
		}
	}

	cout << st.top() << endl;

	return 0;
}


