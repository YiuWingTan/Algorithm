/*
켜똑 위켜
*/

#include<iostream>
#include<vector>
using namespace std;


vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> result;

	string target = "";

	for (int i = 0; i < words.size(); i++) target += words[i];

	int len = s.size()- target.size();

	if (len<0) return result;

	int k = 0;
	while (k <= len)
	{
		int i = 0;
		while (i < target.size() && s[k + i] == target[i]) i++;
		if (i == target.size())
		{
			result.push_back(k);
			k += i;
		}
		else k++;
	}

	return result;
}

int main()
{
	vector<string> pattern{ "foo","bar" };
	auto result = findSubstring("barfoothefoobarman",pattern);

	for (int i = 0; i < result.size(); i++)
	{
		printf("%d ",result[i]);
	}

	getchar();
	return 0;
}