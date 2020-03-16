
/*
解决思路
将中序转换为后序然后进行运算

*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int getNumber(string&str,int& i)
{
	int result = 0;
	while (str[i] >= '0'&&str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	i--;
	return result;
}
int getPriority(char c)
{
	switch (c)
	{
	case '+':return 1;
	case '-':return 1;
	case '*':return 2;
	case '/':return 2;
	}
}

int main()
{
	stack<int> number;
	stack<char> oper;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{

		if (str[i] >= '0'&&str[i] <= '9')
		{
			int n = getNumber(str,i);
			number.push(n);
		}
		else 
		{

		}

	}


	return 0;
}


