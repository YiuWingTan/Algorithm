#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> arr;

int max(int i,int j)
{
	return i > j ? i : j;
	
}

//使用备忘录
int getNumber(string &s,int i)
{
	if (i >= s.size()) return 1;
	if (arr[i] != -1) return arr[i];

	if (s[i] == '0') { arr[i] = 0; return arr[i]; }
	else if (i + 1 < s.size())
	{
		if (s[i] < '2' || (s[i] == '2' && s[i + 1] <= '6'))
		{
			if (s[i + 1] == '0') arr[i] = getNumber(s,i+2);
			else arr[i] = getNumber(s, i + 1) + getNumber(s, i + 2);
		}
		else arr[i] = getNumber(s,i+1);

		return arr[i];
	}

	arr[i] = getNumber(s,i+1);
	return arr[i];
}


//使用动态规划
int getNumber(string&s)
{
	if (s.size() == 0) return 0;
	if (s.size() == 1) return s[0] == '0' ? 0 : 1;
	if (s[0] == '0') return 0;
	vector<int> dp;
	int len = s.size();
	dp.resize(s.size()+1);
	int begin = s.size()-1;
	dp[dp.size() - 1] = 1;

	for (int i = len - 1; i >= 0; i--)
	{

		if (s[i] == '0')
		{
			if (i + 1 < len&&s[i + 1] == '0') return 0;
			dp[i] = dp[i + 1];
			continue;
		}
		if (i + 1 < len)
		{
			//后一项为0
			if (s[i + 1] == '0'&&s[i] > '2') return 0;
			if (s[i + 1] == '0') { 
				dp[i] = dp[i + 1]; 
				i--;
				if (i >= 0) dp[i] = dp[i+1];
				continue;
			}
			//后一项不为0
			if (s[i] > '2' || (s[i] == '2'&&s[i + 1] > '6')) { dp[i] = dp[i + 1]; continue; }
			dp[i] = dp[i+1]+1;
		}
		else dp[i] = dp[i+1];
	}

	return dp[0];
}

int numDecodings(string s) {

	if (s.size() == 0) return 0;
	int n = getNumber(s);
	return n;
}


int main()
{
	string s = "1212";
	int count = numDecodings(s);
	cout << count << endl;


	getchar();
	return 0;
}