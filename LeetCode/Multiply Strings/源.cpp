#include<vector>
#include<string>
#include<iostream>

using namespace std;

string multiply(string num1, string num2) {

	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 == 0) return num2;
	if (len2 == 0) return num1;

	//检测其中一个是否为0
	if (num1[0] == '0' || num2[0] == '0') return "0";
	string r(len1+len2, '0');
	string result = "";
	int stIndex = r.size()-1;
	int muloffset = 0;//乘法进位
	int addoffset = 0;//加法进位
	int add = 0;
	int mul = 0;
	for (int i = len2 - 1; i >= 0; i--)
	{
		int k = stIndex;
		muloffset = 0;
		addoffset = 0;
		for (int j = len1-1; j >= 0; j--)
		{
			mul = (num1[j] - '0')*(num2[i] - '0') + muloffset;
			muloffset = mul / 10;
			add = (mul % 10) + (r[k] - '0') + addoffset;
			addoffset = add / 10;
			r[k--] = add % 10+'0';
		}
		r[k] = (muloffset + addoffset) +'0';
		stIndex--;
	}

	for (int i = 0; i < r.size(); i++)
	{
		if (r[i] != '0')
		{
			for (int j = i; j < r.size(); j++) result += r[j];
			break;
		}
	}
	return result;
}

void text1()
{
	string num1 = "1" ;
	string num2 = "99" ;

	string result = multiply(num1,num2);

	printf("%s*%s的结果为:%s\n",num1.c_str(),num2.c_str(),result.c_str());

}
void text2()
{
	string num1 = "0";
	string num2 = "99";

	string result = multiply(num1, num2);

	printf("%s*%s的结果为:%s\n", num1.c_str(), num2.c_str(), result.c_str());
}
void text3()
{
	string num1 = "123";
	string num2 = "456";

	string result = multiply(num1, num2);

	printf("%s*%s的结果为:%s\n", num1.c_str(), num2.c_str(), result.c_str());
}



int main()
{
	text1();
	text2();
	text3();
	getchar();
	return 0;
}