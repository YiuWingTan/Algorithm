#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

string simplifyPath(string path) {

	if (path.size() == 0 || path[0] != '/') return "";
	string str;
	stack<char> st;

	if (path[path.size() - 1] != '/') path.push_back('/');
	for (int i = 0; i < path.size(); i++)
	{
		if (i + 2 < path.size() && path[i] == path[i+1]&&path[i] == '.')
		{
			if(!st.empty()) st.pop();
			while (!st.empty() && st.top() != '/') st.pop();
			if (!st.empty()) st.pop();
			i += 2;
		}
		else if (i + 1 < path.size() && path[i] == '.'&&path[i + 1] == '/') {
			if(!st.empty()&&st.top() == '/')
				st.pop();
			i++;
			
		}
		else
		{
			if (st.empty() && path[i] != '/') st.push('/');
			st.push(path[i]);
		}
		if(path[i] == '/')
		while (i + 1 < path.size() && path[i] == path[i + 1])++i;

		
	}

	if (!st.empty()&&st.top() == '/') st.pop();
	if (st.empty()) st.push('/');
	str.resize(st.size());
	for (int i = str.size() - 1; i >= 0; i--) { str[i] = st.top(); st.pop(); }

	return str;
}


int main()
{
	cout << simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///")<<endl;

	getchar();
	return 0;
}


