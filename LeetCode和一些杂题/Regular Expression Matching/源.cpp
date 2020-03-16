/*
	难度 困难，主题 回溯，动态规划
*/
#include<vector>
#include<iostream>
using namespace std;

bool isMatch(string s, string p) {

	if (p.size() == 0) return s.size() == 0;

	bool first = (!s.empty()&&(s[0]==p[0]||p[0]=='.'));

	if (p.size()>=2&&p[1] == '*')
	{
		return isMatch(s,p.substr(2,p.size()-2))||(first&&isMatch(s.substr(1,s.size()-1),p));
	}
	else 
	{
		return first&&isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
	}

}

int main()
{
	string str = "hellow world!@tanyaorong";
	bool result = isMatch("ab",".**");

	cout << result;

	getchar();
	return 0;
}