#include<iostream>
#include<string>
using namespace std;
using std::string;
string convert(string s, int numRows);


int main()
{
	int n;
	string result;
	getline(cin, result);
	cin >> n;
	string s = convert(result,n);

	cout << s << endl;

	getchar();
	cin >> n;
}

string convert(string s, int numRows) {

	string result;
	string *ss = new string[numRows];
	int mark = (numRows - 1);
	int n = 1;
	int j = 0;
	int offset = 0;
	for (int i = 0; i < s.size(); i++)
	{
		j = (i+1)%mark;
		//if (j == 1) cout << "込込込"<<endl;
		//if ((i + 1) == 7) { cout << j << endl<<mark<<endl; }
		if ((j == 1||mark == 1)&&i!=0)
		{
			//cout << "込込込"<<endl;
			mark += (numRows - 1);
			n *= -1;
		}
		ss[offset] += s[i];
		offset += n;
	}

	for (int i = 0; i < numRows; i++)
		result += ss[i];
	return result;
}