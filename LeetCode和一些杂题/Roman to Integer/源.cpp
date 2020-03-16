/*
	难度中等 ，主题 string,math
*/

#include<iostream>
#include<vector>

using namespace std;

int romanToInt(string s) {

	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case 'I':
			if (s[i + 1] == 'V')
			{
				n += 4;
				i++;
			}
			else if(s[i+1]=='X')
			{
				n += 9;
				i++;
			}
			else
			{
				n += 1;
			}

			break;
		case 'X':
			if (s[i + 1] == 'L')
			{
				n += 40;
				i++;
			}
			else if(s[i+1]=='C')
			{
				n += 90;
				i++;
			}
			else
			{
				n += 10;
			}
			break;
		
		case 'C':
			if (s[i + 1] == 'D')
			{
				n += 400;
				i++;
			}
			else if(s[i+1]=='M')
			{
				n += 900;
				i++;
			}
			else
			{
				n += 100;
			}
			break;
		
		case 'M':
			n += 1000;
			break;
		case 'L':
			n += 50;
			break;
		case 'V':
			n += 5;
			break;
		case 'D':
			n += 500;
			break;
		}
	}
	return n;
}

int main()
{
	printf("%d\n", romanToInt("LVIII"));

	getchar();
	return 0;
}