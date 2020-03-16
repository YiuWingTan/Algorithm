#include<iostream>
#include<vector>
#include<string>
using namespace std;

string toLowerCase(string str) {

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= 'Z'&&str[i] >= 'A')
		{
			str[i] += 32;
		}
	}

	return str;
}


int main()
{

}