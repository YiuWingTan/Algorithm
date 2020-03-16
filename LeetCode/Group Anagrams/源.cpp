#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;


int hashC[26];



void show(vector<vector<string>> &strs)
{
	for (int i = 0; i < strs.size(); i++)
	{
		for (int j = 0; j < strs[i].size(); j++)
			cout << strs[i][j]<<" ";
		cout << endl;
	}
}

//超过时间限制
/*
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> result;
	if (strs.size() == 0) return result;

	queue<string> que;
	for (int i = 0; i < strs.size(); i++)
	{
		que.push(strs[i]);
	}
	int n = 0;
	while (!que.empty())
	{
		string s = que.front();
		vector<string> answer;
		answer.push_back(s);
		que.pop();
		n = que.size();

		for (int i = 0; i < n; i++)
		{
			for (int i = 0; i < s.size(); i++)
			{
				hashC[(s[i] - 'a')]++;
				cout << s[i] << hashC[s[i] - 'a'] << endl;
			}
			string t = que.front();
			que.pop();
			int j = 0;
			for (; j < t.size(); j++)
			{
				if (hashC[t[j] - 'a'] == 0)
					break;
				hashC[t[j] - 'a']--;
				cout << t[j] << hashC[t[j] - 'a']<<endl;
			}
			if (j == t.size()&&s.size() == t.size())
			{
				answer.push_back(t);
			}
			else que.push(t);
			for (int i = 0; i < s.size(); i++)
			{
				hashC[(s[i] - 'a')] = 0;
			}
		}
		
		result.push_back(answer);
	}

	return result;
}
*/

vector<vector<string>> groupAnagrams(vector<string>& strs)
{

	vector<vector<string>> results;
	if (strs.size() == 0) return results;
	map<string, vector<string>> m;
	for (int i = 0; i < strs.size(); i++)
	{
		string s = strs[i];
		sort(s.begin(), s.end());
		m[s].push_back(strs[i]);
	}

	for (auto n = m.begin(); n != m.end(); n++)
	{
		results.push_back(n->second);
	}

	return results;
}

void text1()
{
	vector<string> strs ={ "yup","","yup","upp","" };
	auto results = groupAnagrams(strs);
	show(results);
}

int main()
{
	text1();

	getchar();
	return 0;

}