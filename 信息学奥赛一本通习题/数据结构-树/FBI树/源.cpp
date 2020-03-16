

#include<iostream>
#include<string>
using namespace std;

string str;

char judgeType(int a,int b)
{
	bool isF = false, isB = false;
	
	for (int i = a; i <= b; i++)
	{
		if (str[i] == '0') isB = true;
		if (str[i] == '1') isF = true;

		if (isB&&isF) return 'F';
	}

	return isB ? 'B' : 'I';

}

void back(int a,int b)
{
	if (a >= b)
	{
		if (a == b) cout << judgeType(a,b);

		return;
	}

	int mid = (a + b) / 2;

	back(a,mid);
	back(mid+1,b);

	cout << judgeType(a,b);
}


int main()
{
	int n;
	cin >> n;
	cin >> str;
	back(0,str.size()-1);



	return 0;
}


