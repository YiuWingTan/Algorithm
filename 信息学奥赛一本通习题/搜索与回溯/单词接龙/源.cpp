

/*

1220：单词接龙

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 2834     通过数: 1607
【题目描述】
单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如beast和astonish，如果接成一条龙则变为beastonish，另外相邻的两部分不能存在包含关系，例如at和atide间不能相连。

【输入】
输入的第一行为一个单独的整数n(n≤20)表示单词数，以下n行每行有一个单词（只含有大写或小写字母，长度不超过20），输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在。

【输出】
只需输出以此字母开头的最长的“龙”的长度。

【输入样例】
5
at
touch
cheat
choose
tact
a
【输出样例】
23


【算法分析】
	注意找的是最小重叠部分

*/

#include<iostream>
#include<string>
using namespace std;
int k;
int maxlen;
int isused[21];
string words[21];

inline int max(int i,int j)
{
	return i > j ? i : j;
}

int link(string&tar,string &src,int len)
{
	for (int i = len-1; i >=0; i--)
	{
		if (tar[i] == src[0]) {

			//查看能否进行组合
			int j = 0;
			for (; i+j<len && tar[j + i] == src[j]; j++);
			if (i + j == len) return i ==0?0:j;
		}
	}
	return 0;
}


void klondike(string&tar,int len)
{
	if (len > maxlen) maxlen = len;

	//寻找单词
	for (int i = 0; i < k; i++)
	{
		if (isused[i] == 2) continue;

		int n = link(tar,words[i],len);

		if (n == 0) continue;

		for (int j = 0; j < words[i].size() - n; j++)
			tar[j + len] = words[i][j+n];

		isused[i]++;

		

		klondike(tar,len+ words[i].size() - n);

		isused[i]--;

	}


}


int main()
{
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> words[i];
	}

	char w;
	cin >> w;

	string tar;
	tar.resize(400);
	for (int i = 0; i < k; i++)
	{
		if (words[i][0] == w)
		{
			
			for (int j = 0; j < words[i].size(); j++)
				tar[j] = words[i][j];
			isused[i]++;
			klondike(tar,words[i].size());
			isused[i]--;
		}
	}

	cout << maxlen << endl;

	return 0;
}








