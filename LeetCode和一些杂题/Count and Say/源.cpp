#include<iostream>
#include<vector>
using namespace std;



vector<string> result = {"","1","11","21","1211","111221"};
string countAndSay(int n) {

	if (n<result.size() - 1) return result[n];

	for (int i = result.size(); i <= n; i++)
	{
		string target = "";
		string prev = result[i - 1];

		for (int j = 0; j<prev.size(); j++)
		{
			int num = 1;
			while (j + 1<prev.size() && prev[j + 1] == prev[j]) { num++; j++; }
			target += (num + '0');
			target += prev[j];
		}
		result.push_back(target);
	}

	return result[n];
}


int main()
{


	getchar();
	return 0;
}
