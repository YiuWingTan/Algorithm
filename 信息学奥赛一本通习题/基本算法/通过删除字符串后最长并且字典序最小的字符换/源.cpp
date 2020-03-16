#include<iostream>
#include<vector>
#include<string>
using namespace std;



void judge(string&str,string &target)
{
	if (target.size() == str.size())
	{
		str = str > target ? target : str;
	}
	else if (target.size() > str.size())
	{
		str = target;
	}
}

string findLongestWord(string s, vector<string>& d) {

	
	
	string result = "";
	
	for (int i = 0; i < d.size(); i++)
	{
		
		//判断是否能通过删除来变成 d[i]
		int k = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == d[i][k])
			{
				k++;
			}
		}

		if (k == d.size())
		{
			//能进行删除后得到
			judge(result,d[i]);
		}
	}

	return result;
}


int main() {



	getchar();
	return 0;
}

