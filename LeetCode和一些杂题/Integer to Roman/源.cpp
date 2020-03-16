/*
	难度 中等 主题 数学，string
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<string>> math{
	{ "" },
	{ "","I","II","III","IV","V","VI","VII","VIII","IX" },
	{ "" ,"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
	{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
	{"","M","MM","MMM"}
};



string intToRoman(int num) {
	
	string result = "";
	int mark = 1000;
	int index = 4;

	while (mark >= 1)
	{
		int n = num / mark;
		result += math[index][n];
		num -= n*mark;
		mark /= 10;
		index--;
	}
	return result;
}


int main()
{
	printf(intToRoman(1994).c_str());

	getchar();
	return 0;
}