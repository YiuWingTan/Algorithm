#include<iostream>
#include<string>
#include<vector>
using namespace std;
using std::string;
int min(int i,int j)
{
	return i > j ? j:i;
}

/*һ���ǳ���Ч��JAVAʵ�ְ�*/
/*

public class Solution {
	private int lo, maxLen;

	public String longestPalindrome(String s) {
		int len = s.length();
		if (len < 2)
			return s;

		for (int i = 0; i < len-1; i++) {
			extendPalindrome(s, i, i);  //assume odd length, try to extend Palindrome as possible
			extendPalindrome(s, i, i+1); //assume even length.
		}
	return s.substring(lo, lo + maxLen);
}

	private void extendPalindrome(String s, int j, int k) {
		while (j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
			j--;
			k++;
		}
		if (maxLen < k - j - 1) {
			lo = j + 1;
			maxLen = k - j - 1;
		}
	}
}

*/


string longestPalindrome(string s)
{
	vector<int> hash[127];
	string str;
	int maxLength = 1;
	int mi =0,mj =0;

	for (int i = 0; i < s.size(); i++)
	{
		int n = s[i];

		//���ظ��ֶΣ�����Ѱ��
		for (int j = 0; j <hash[n].size(); j++)
		{
			int lo = hash[n][j];
			int hi = i;

			if ((hi - lo+1) > maxLength)
			{
				while (lo<hi)
				{
					if (s[lo] != s[hi]) break;
					lo++;
					hi--;
				}
				if (lo >= hi && (i - hash[n][j] + 1)>maxLength) {
					//�ҵ�һ�����Ĵ���,�������ĳ��ȱ�֮ǰ�ҵ�����Ļ��Ĵ���Ҫ��
					maxLength = i - hash[n][j] + 1;
					mi = hash[n][j];
					mj = i;
				}
			}
			else break;
		}
		//����ĸ��λ��ѹ������λ��
		hash[n].push_back(i);
		
	}

	for (int i = mi; i <= mj; i++)
		str += s[i];

	//cout << "��Ļ��Ĵ���"<<maxLength;

	return str;
}

 
int main()
{
	string s;
	getline(cin, s);
	string str = longestPalindrome(s);
	cout << str;

	getchar();

	return 0;
}