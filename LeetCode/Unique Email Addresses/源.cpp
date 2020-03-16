/*
主题 string 难度简单
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void doFunction(string &str)
{
	int po, pl, ma;
	po = pl = ma = -1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '@') { ma = i; break; }
		if (str[i] == '.') { str.erase(str.begin()+ i); i--; continue; }
		if (str[i] == '+'&&pl == -1) { pl = i; }
	}

	str.erase(str.begin()+pl,str.begin()+ma);
}

int numUniqueEmails(vector<string>& emails) {

	for (int i = 0; i < emails.size(); i++)
	{
		doFunction(emails[i]);
	}

	for (int i = 0; i < emails.size(); i++)
	{
		for (int j = i+1; j < emails.size(); j++)
		{
			if (emails[i].size() == emails[j].size() && emails[i] == emails[j])

			{
				emails.erase(emails.begin() + j);
				j--;
			}
			
		}
	}

	return emails.size();
}

int main()
{
	vector<string> emails;
	emails.push_back("testemail+david@lee.tcode.com");
	emails.push_back("test.email+alex@leetcode.com");
	emails.push_back("test.e.mail+bob.cathy@leetcode.com");

	int num = numUniqueEmails(emails);

	

	printf("有效的email个数是  %d",num);

	getchar();
	return 0;
}