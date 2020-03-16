#include<iostream>
#include<vector>
#include<string>
using namespace std;


void get(string &str,string &pattern,vector<string>& result,int i,int n)
{

	if (n >= 5 || i >= str.size())
	{
		if (n == 5 && i == str.size())
		{
			result.push_back(pattern);
		}
		return;
	}
	if(n!=1)
	pattern.push_back('.');

	if (i + 2 < str.size()&&str[i]!='0')
	{
		int v = (str[i] - '0') * 100 + (str[i + 1] - '0') * 10 + (str[i + 2] - '0');
		if (v <= 255)
		{
			
			pattern.append(str,i,3);
			get(str, pattern, result, i + 3, n + 1);
			pattern.pop_back(); pattern.pop_back();
			pattern.pop_back();
		}
	}
	

	if (i + 1 < str.size()&&str[i]!='0')
	{
		pattern.append(str,i,2);
		get(str,pattern,result,i+2,n+1);
		pattern.pop_back(); pattern.pop_back();
	}

	pattern.push_back(str[i]);
	get(str,pattern,result,i+1,n+1);
	pattern.pop_back();

	if(n!=1)
	pattern.pop_back();
}

vector<string> restoreIpAddresses(string s) {

	vector<string> result;
	if (s.size() < 4||s.size()>16) return result;
	string pattern = "";
	get(s,pattern,result,0,1);

	return result;
}


int main()
{
	string str = "010010";
	auto result = restoreIpAddresses(str);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<endl;
	}

	getchar();
	return 0;
}
