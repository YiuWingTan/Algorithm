

#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> re;
void permutation(string&s,int len,int n)
{
	if (n == len)
	{
		re.push_back(s);
		return;
	}

	for (int i = n; i < len; i++)
	{
		std::swap(s[n],s[i]);
		permutation(s,len,n+1);
		std::swap(s[n],s[i]);
	}


}


int main()
{
	string str;

	getline(cin,str);

	
	permutation(str,str.size(),0);


	for (int i = 0; i < re.size(); i++)
	{
		for (int j = 1; j < re.size() - i; j++)
		{
			if (re[j] < re[j - 1])
				swap(re[j],re[j-1]);
		}
	}



	for (int i = 0; i < re.size(); i++)
		cout << re[i] << endl;


	return 0;
}



