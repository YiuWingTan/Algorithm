#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


string minWindow(string s, string t) {

	if (s.size() < t.size()) return "";

	string result;
	int left = 0,right = 0;
	int minleft = 0, minright = 0;
	int min = INT_MAX, cnt = 0;
	vector<int> ans; ans.resize(256,0);

	for (int i = 0; i < t.size(); i++) ++ans[t[i]];

	for (int i = 0; i < s.size(); i++)
		if (ans[s[i]] > 0) { left = right = i; break; }

	while (left < s.size() && right < s.size())
	{
		while (cnt != t.size() && right < s.size())
		{
			if (ans[s[right++]]-- >= 1) 
				cnt++;
		}
		if (cnt == t.size()) {
			if (right - left< min) { min = right - left; minleft = left; minright = right-1; }
			
		}
		else 
			break;
		
		do
		{
			if (ans[s[left++]]++ == 0)
			{
				cnt--;
			}
		} while (left<s.size()&&ans[s[left]] < 0);
		
		if (cnt == t.size()) {
			if (right - left< min) { min = right - left; minleft = left; minright = right - 1; }

		}
	}

	for (minleft; minleft <= minright&&min!=INT_MAX; minleft++) result += s[minleft];
	return result;
}

int main()
{
	/*
	"aaflslflsldkalskaaa"
	"aaa"

	"aaaaaaaaaaaabbbbbcdd"
	"abcdd"
	*/
	string s = "bba";
	string t = "abss";

	cout << minWindow(s,t);

	getchar();
	return 0;
}

