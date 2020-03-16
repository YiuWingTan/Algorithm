#include<iostream>
#include<vector>


using namespace std;

char str[1001];

int __hash[26];

int main()
{

	while (cin >> str)
	{
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			__hash[(str[i] - 'a')]++;

		int count = 0;
		char c;
		for (int i = 0; i < 26; i++)
		{
			if (__hash[i] > count)
			{
				count = __hash[i];
				c = i + 'a';
			}
		}

		cout << c << " " << count<<endl;
	}


	return 0;
}

