#include<iostream>
#include<vector>
#include<string>
using namespace std;


int StrToInt(string str) {

	if (str.size() == 0) return 0;

	int scale = 1;
	int n = 0;
	int val = 0;
	if (str[0] == '-') scale = -1;
	if (str[0] == '-' || str[0] == '+') n++;

	while (n < str.size() && (str[n] >= '0'&&str[n] <= '9')) {
		val = val * 10 + (str[n] - '0');
		n++;
	}

	return n == str.size() ? scale*val:0;

}


int main()
{
	cout << StrToInt("-+55151");

	getchar();
	return 0;
}


