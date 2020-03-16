#include<iostream>
#include<vector>
#include<string>

using namespace std;


//暴力求解 - 非活动窗口法
/*
vector<int> findAnagrams(string s, string p) {

	if (s.size() < p.size()||s.size() == 0) return{};

	int patt[26] = {0};
	int ans[26] = {0};
	int targetnum = 0;
	int num = 0;
	int len = p.size();
	vector<int> result;



	for (int i = 0; i < len; i++)
	{
		if (patt[p[i] - 'a'] == 0) targetnum++;
		patt[p[i] - 'a']++;
	}

	for (int i = 0; i < len; i++)
	{
		if (ans[s[i] - 'a'] == 0) {
			num++;
		}
		ans[s[i] - 'a']++;
	}

	for (int i = 0; i < s.size()-len+1; i++)
	{
		if (num == targetnum)
		{
			bool hr = true;
			for (int j = 0; j < len; j++)
			{
				//cout << ans[p[j] - 'a'] << endl;
				hr &= ans[p[j] - 'a'] == patt[p[j] - 'a'];
			}
			if(hr)
			result.push_back(i);
		}
		if (--ans[s[i] - 'a'] == 0) num--;
		if (i + len<s.size()&&++ans[s[i + len] - 'a'] == 1)num++;
	}
	return result;
}
*/

//滑动窗口法
vector<int> findAnagrams(string s, string p)
{
	vector<int> ans(26,0);

	int cnt = p.size();
	int left = 0, right = 0;
	vector<int> result;

	for(int i = 0;i<p.size();i++)
	{
		ans[p[i] - 'a']++;
	}


	while (left < s.size() && right < s.size())
	{
		ans[s[right] - 'a']--;
		if (ans[s[right] - 'a'] >= 0) {
			cnt--;

		}
		right++;
		if (cnt == 0) result.push_back(left);
		//当前的滑动窗口的数量已经大于p的长度了
		if (right - left == p.size())
		{
			//判断左边界需要进行恢复的字符是否是在p中的字符
			//当这个字符的ans值
			if (ans[s[left] - 'a'] >= 0)cnt++;
			ans[s[left] - 'a']++;
			left++;
		}
	}
	return result;
}



int main()
{
	string s = "abab";
	string p = "ab";

	auto result = findAnagrams(s,p);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "  ";

	getchar();
	return 0;
}
