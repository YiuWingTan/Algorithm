#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//第一次实现
//int longestValidParentheses(string s) {
//	
//	int dp = 0;
//	int max = 0;
//	int len = s.size();
//	if (len <= 1)return max;
//
//	for (int i = 0; i < len; i++)
//	{
//		for(int j = i;j<len;j++)
//		{
//			 if (s[j] == '(') dp--;
//			 else if (s[j] == ')') dp++;
//			 if (dp == 0 && (j - i + 1 > max)) { max = j - i + 1; }
//			 if (dp > 0)
//			 {
//				 //左边有多余的)
//				 i = j;
//				 break;
//			 }
//		}
//		dp = 0;
//	}
//	return max;
//}

int longestValidParentheses(string s)
{
	int max = 0;
	int len = s.size();
	stack<int> st;

	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			st.push(i);
		}
		else if(!st.empty())
		{
			
			s[st.top()] = '0';
			s[i] = '0';
			st.pop();
		}
	}

	int l = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '0')
		{
			l++;
			if (l > max) max = l;
		}
		else l = 0;
	}

	
	return max;
}

int main()
{

	int n = longestValidParentheses(")()()()(((()))()(()(((()");

	printf("最大的合法()为 %d个\n",n);

	getchar();
	return 0;

}