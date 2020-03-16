/*
  难度 简单   主题 string
*/
#include<iostream>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0];

	int mark = -1;

	for (int i = 1; i < strs.size(); i++)
	{
		int j = 0;
		for (; j < strs[i].size() && strs[0][j] == strs[i][j]; j++);
		mark = mark <= j&&mark>=0 ? mark : j;
		if (mark == 0) return "";
	}

	return strs[0].substr(0,mark);
}


int main()
{
	

	getchar();
	return 0;
}