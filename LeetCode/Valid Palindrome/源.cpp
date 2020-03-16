#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isPalindrome(string s) {

	int lo = 0;
	int hi = s.size() - 1;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90) s[i] = s[i] + 32;
	}

	while (lo<hi)
	{
		while (lo < hi && !((s[lo] >= 97 && s[lo] <= 122) || (s[lo] >= 48 && s[lo] <= 57)))lo++;
		while (lo < hi && !((s[hi] >= 97 && s[hi] <= 122) || (s[hi] >= 48 && s[hi] <= 57))) hi--;

		if (s[lo] != s[hi]) return  false;
	}

	return true;

}


int main()
{


	getchar();
	return 0;
}
