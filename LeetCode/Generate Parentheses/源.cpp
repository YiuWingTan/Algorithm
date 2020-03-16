/*
	难度 中等 主题 回溯
*/

#include<vector>
#include<iostream>

using namespace std;

void solve(int num,int left,string str,vector<string>&pattern)
{
	if (num == 0) { 
		pattern.push_back(str);
		return; 
	}
	if (left<num) solve(num,left+1,str+'(',pattern);

	if (left > 0)
	{
		solve(num-1, left-1, str+')', pattern);
	}
}

vector<string> generateParenthesis(int n) {
	
	vector<string> result;
	solve(n,0,"",result);
	return result;
}


int main()
{
	auto result = generateParenthesis(3);

	for (int i = 0; i < result.size(); i++)
	{
		printf("%s\n", result[i].c_str());
	}

	getchar();
	return 0;
}