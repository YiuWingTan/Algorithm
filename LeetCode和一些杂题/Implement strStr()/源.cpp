/*
	难度 简单 主题 双指针 string
*/
#include<iostream>
#include<vector>

using namespace std;

int strStr(string haystack, string needle) {
	if (needle.size() == 0) return 0;

	int up = haystack.size() - needle.size();

	if (up < 0) return -1;

	int i = 0;
	while (i <=up)
	{
		int j = 0;
		while (j<needle.size()&&haystack[i + j] == needle[j]) j++;
		if (j == needle.size()) return i;
		else i++;
	}

	return -1;
}

int main()
{
	getchar();
	return 0;
}