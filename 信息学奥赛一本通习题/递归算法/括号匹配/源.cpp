#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;


char str[100][100];


int main()
{
	
	string tmp;
	stack<int> left;

	while (cin >> tmp)
	{
		string str(tmp.size(),' ');
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == '(')
			{
				left.push(i);
			}
			else if (tmp[i] == ')')
			{
				if (left.empty())
				{
					str[i] = '?';
				}
				else {
					left.pop();
				}
			}
		}

		while (!left.empty())
		{
			str[left.top()] = '$';
			left.pop();
		}

		cout << tmp<<endl;
		cout << str<<endl;

		tmp.clear();
	}

	return 0;
}