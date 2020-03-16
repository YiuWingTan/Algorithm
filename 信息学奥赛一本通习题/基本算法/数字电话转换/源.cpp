#include<iostream>
#include<vector>

using namespace std;

vector<string> mm = {
	"",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};

void make(string &str,int k,int j,string &ans,vector<string>&result)
{
	if (j >= ans.size())
	{
		result.push_back(ans);
		return;
	}

	for (int i = 0; i < mm[str[k] - '0'].size(); i++)
	{
		ans[j] = mm[str[k] - '0'][i];
		make(str,k+1,j+1,ans,result);
	}


}

vector<string> letterCombinations(string digits) {

	vector<string> result;
	string ans;
	ans.resize(digits.size());

	make(digits,0,0,ans,result);

	return result;
}







