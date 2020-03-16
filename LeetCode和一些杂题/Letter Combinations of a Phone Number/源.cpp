/*
	难度 中等 主题 回溯

*/

#include<vector>
#include<iostream>

using namespace std;

vector<vector<char>> pattern{
	{'*'},
	{ 'a','b','c' },
	{ 'd','e','f' },
	{ 'g','h','i' },
	{ 'j','k','l' },
	{ 'm','n','o' },
	{ 'p','q','r','s' },
	{ 't','u','v' },
	{ 'w','x','y','z' },
};

void solve(vector<string>& result,string str,int n)
{
	
	if (n >= str.size()) result.push_back(str);
	else
	{
		int len = pattern[(int)str[n] - 49].size();
		int mark = (int)str[n] - 49;
		for (int i = 0; i < len; i++)
		{
			str[n] = pattern[mark][i];
			solve(result,str,n+1);
		}
	}
}

vector<string> letterCombinations(string digits) {

	vector<string> result;
	if (digits.size() == 0) return result;

	

	solve(result,digits,0);

	return result;
}

int main()
{
	
	auto list = letterCombinations("23");

	for (int i = 0; i < list.size(); i++)
	{
		printf("%s\n",list[i].c_str());
	}

	getchar();
	return 0;
}