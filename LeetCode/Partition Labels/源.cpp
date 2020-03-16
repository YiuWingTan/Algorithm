#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<math.h>
using namespace std;


int max(int i,int j)
{
	return i > j ? i : j;
}

int ans[26];

vector<int> partitionLabels(string S) {

	if (S.size() == 0) return{};

	vector<int> result;

	for (int i = 0; i < S.size(); i++)
	{
		ans[S[i] - 'a'] = i;
	}

	int st = 0;
	int end = 0;

	for (int i = 0; i < S.size(); i++)
	{
		end = max(ans[S[i] - 'a'],end);//此处是贪心算法的关键

		if (end == i)
		{
			result.push_back(end - st+1);
			end = st = end + 1;
		}
	}

	return result;
}


int main()
{
	string str = "ababcbacadefegdehijhklij";

	partitionLabels(str);

	getchar();
	return 0;
}
