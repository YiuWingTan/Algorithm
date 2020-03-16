
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<char> mid;
vector<char> back;


void calOrder(string&str,int &i)
{
	if (str[i] == '.') {
		return;
	}
	int tmp = i;
	calOrder(str,++i);

	mid.push_back(str[tmp]);

	calOrder(str,++i);

	back.push_back(str[tmp]);
}


int main()
{
	string str;
	cin >> str;
	int i = 0;
	calOrder(str,i);
	for (int i = 0; i < mid.size(); i++) cout << mid[i];
	cout << endl;
	for (int i = 0; i < back.size(); i++) cout << back[i];
	cout << endl;

	return 0;
}


