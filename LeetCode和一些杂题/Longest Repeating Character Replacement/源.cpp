#include<iostream>
#include<vector>

using namespace std;

int max(int i,int j)
{
	return i > j ? i : j;
}

/*
使用滑动窗口
*/
int characterReplacement(string s, int k) {

	//不够正确可能字符串有完全重复的字符串
	
	if (s.size() == 0||s.size()<=k) return s.size();

	int maxCharCount= 0;
	int result = 0;
	int start = 0,end = 0;
	vector<int> tmp(26,0);

	for (end = 0; end < s.size(); end++)
	{
		tmp[s[end] - 'A']++;
		if (tmp[s[end] - 'A'] > maxCharCount) maxCharCount = tmp[s[end] - 'A'];

		while (end - start + 1 - maxCharCount > k)
		{
			//当字串中个数不同的数量大于k时进行循环，将滑动窗口的左边界往前移动,
			//注意当end == start时就会自动的退出循环因为次时maxcharcount的值为1，而k是大于等于0的.

			tmp[s[start] - 'A']--;//进行滑动窗口的左边界进行滑动
			start++;

			//寻找当前字串的最大值
			maxCharCount = 0;
			for (int i = 0; i < 26; i++)
			{
				if (maxCharCount < tmp[i]) maxCharCount = tmp[i];
			}

		}
		
		result = max(result,end - start+1);
	}

	return result;
}

//功能测试
void text1()
{
	string str = "AAAA";
	int k = 0;

	cout << "最大长度为"<< characterReplacement(str,k)<<endl;
}

//边界测试
void text2()
{

}


int main()
{

	text1();

	getchar();
	return 0;
}
