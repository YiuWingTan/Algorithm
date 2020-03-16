#include<iostream>
#include<vector>
#include<string>
/*
题目描述：
	判断一个string中的回文串的统计
解决方案：
	动态规划
	if (j <= i) { isPalin[i][j] = 1; continue; }
	if (isPalin[i][j - 1] &&s[i] == s[j] && isPalin[i][j - 1] == (j - i)) {
	isPalin[i][j] = isPalin[i][j-1]+1;
	num++;
	}
	else if (isPalin[i + 1][j - 1] && s[i] == s[j]) {
	isPalin[i][j] = isPalin[i+1][j-1]+2; num++; }
	else isPalin[i][j] = 0;
*/
using namespace std;
int isPalin[1000][1000];

int countSubstrings(string s) {

	int num = 0;
	int n =s.size();

	for (int i = 0; i < n; i++)
	{
		isPalin[i][i] = 1;
		num++;
	}

	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i + j >= n) continue;
			int mark = i + j;
			if (isPalin[i][mark - 1] && s[i] == s[mark] && isPalin[i][mark - 1] == (mark - i)) {
				isPalin[i][mark] = isPalin[i][mark - 1] + 1;
				num++;
			}
			else if (isPalin[i + 1][mark - 1] && s[i] == s[mark]) {
				isPalin[i][mark] = 1; num++;
			}
		}
	}

	return num;
}

using namespace std;
int main()
{
	string s = "bbccaacacdbdbcbcbbbcbadcbdddbabaddbcadb";

	cout << "回文字串有 "<< countSubstrings(s)<<" 个"<<endl;

	getchar();
}