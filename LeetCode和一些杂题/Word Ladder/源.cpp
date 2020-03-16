#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

/*

难度：中等，广度优先搜索
*/


///判断两个字符串是否只有一个字符不一样
bool differentOne(string &s1,string&s2)
{
	int count = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (count > 1) return false;
		if (s1[i] != s2[i]) count++;
	}
	return count == 1;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

	wordList.push_back(beginWord);
	vector<bool> marked;
	marked.resize(wordList.size(),false);
	
	int count = 0;
	int size = 1;
	queue<int> que;
	que.push(marked.size() - 1);
	marked[marked.size() - 1] = true;
	while (!que.empty())
	{
		int tar = que.front();
		que.pop();
		
		if (wordList[tar] == endWord) return ++count;
		for(int i = 0;i<wordList.size();i++)
			if (!marked[i] && differentOne(wordList[i], wordList[tar]))
			{
				//cout << wordList[tar]<<"  :"<<wordList[i]<<endl;
				marked[i] = true;
				que.push(i);
			}
		if (--size == 0)
		{
			count++;
			size = que.size();
		}

	}
	return 0;
}


int main()
{

	string st = "hit";
	string ed = "cog";
	vector<string> wordList = { "hot","dot","dog","lot","log" };

	int count = ladderLength(st,ed,wordList);

	cout << count<<endl;

	getchar();
	return 0;
}