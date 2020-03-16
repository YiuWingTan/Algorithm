#include<iostream>
#include<string>
using namespace std;
using std::string;


int myAtoi(string str) {

	//先找到第一个非空的字符
	int sig = 1;
	int start = -1;
	int mark = 1;
	int end = -1;
	for (int i = 0; i < str.size(); i++)
	{
		//找到一个数字了
		if (str[i] >= 48 && str[i] <= 57||(str[i]=='+'||str[i]=='-'))
		{
			
			for (int j = i - 1; j >= 0; j--)
			{
				if (str[j] != ' ') return 0;
			}
			
			if (str[i] == '-') { sig = -1; i++; }
			if (str[i] == '+') { i++; }

			start = end = i;
			if (str[i] < 48 || str[i] > 57) return 0;
			for (int j = i; j < str.size(); j++)
			{
				if (str[j] >= 48 && str[j] <= 57) { end = j; }
				else break;
			}
			break;
		}
		
	}

	

	if (start == -1||end == -1) return 0;
	cout << "start:" << start << endl;
	cout << "end:" << end << endl;
	long long rev = 0;


	for (int i = start; i <= end; i++)
	{
		rev = rev * 10 + (str[i] - 48);
	}

	if (sig > 0)
	{
		return rev>INT_MAX ?INT_MAX : sig*rev;
	}

	return sig*rev<INT_MIN?INT_MIN:sig*rev;
}

int main()
{
	string s;
	getline(cin,s);
	int n = myAtoi(s);

	cout << n<<endl;
	getchar();
}