
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int cal(int a, int b, char c)
{
	int k = a;
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '^': 
		while (--b > 0) a *= k;
		return a;
	case '/':return a / b;
	case '*':
		return a * b;
	}
	return 0;
}

int getNumber(string&str,int &i)
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

int calate(string& str,int& i)
{
	stack<int> numbers;
	stack<char> oper;

	for (; i < str.size(); i++)
	{
		int number = 0;
		if (str[i] == '(')
		{
			number = calate(str, i+=1);
			numbers.push(number);
		}
		else if(str[i] != ')')
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				number = getNumber(str,i);
				numbers.push(number);
			}
			else
			{
				oper.push(str[i]);
				continue;
			}
		}
		else
		{
			
			break;
		}


		//进行乘除法的计算
		if (!oper.empty() && (oper.top() == '*'||oper.top() == '/'||oper.top() == '^'))
		{
			int b = numbers.top(); numbers.pop();
			int a = numbers.top(); numbers.pop();
			int c = cal(a, b, oper.top());
			numbers.push(c);
			oper.pop();
		}
	}

	//计算出结果
	
	while (!oper.empty())
	{
		int b = numbers.top(); numbers.pop();
		int a = numbers.top(); numbers.pop();
		char c = oper.top();
		oper.pop();
		if (!oper.empty() && oper.top() == '-')
		{
			a *= -1;
			oper.pop();
			oper.push('+');
		}
		numbers.push(cal(a, b,c));
		
	}
	int c = numbers.top();
	return numbers.top();;
}


int main()
{

	string str;
	cin >> str;
	int index = 0;
	cout << calate(str, index) << endl;

	return 9;

}


