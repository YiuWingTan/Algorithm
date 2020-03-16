#include<iostream>
#include<vector>
using namespace std;

void generator(vector<string>&result,string& str,int left,int leftNum,int rightNum,int k)
{
	if (leftNum == 0 && rightNum == 0)
	{
		result.push_back(str);
		return;
	}

	if (leftNum > 0)
	{
		str[k] = '(';
		generator(result,str,left+1,leftNum-1,rightNum,k+1);
	}

	if (rightNum > 0&&left>0)
	{
		str[k] = ')';
		generator(result,str,left-1,leftNum,rightNum-1,k+1);
	}
}

vector<string> generateParenthesis(int n) {


	vector<string> result;
	string str;
	str.resize(n*2);
	generator(result,str,0,n,n,0);
	return result;

}


int main()
{

	getchar();
	return 0;
}



