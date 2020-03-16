#include<iostream>
#include<vector>
using namespace std;

int arr[1000][1000];

int countSubstrings(string s) {
	
	for (int i = 0; i < s.size(); i++)
	{
		arr[i][i] = 1;
	}
	int mark = s.size();

	for (int k = 1; k < s.size(); k++) {

		for (int i = 0; i < s.size(); i++)
		{
			if (i + k >= s.size()) break;
			int j = i + k;

			if (s[i] != s[j]) continue;

			if (arr[i + 1][j - 1] != 0 || i + 1 >= j - 1)
			{
				arr[i][j] = 1;
				mark++;
			}

		}

	}

	return mark;;
}

int main()
{


	getchar();
	return 0;
}



