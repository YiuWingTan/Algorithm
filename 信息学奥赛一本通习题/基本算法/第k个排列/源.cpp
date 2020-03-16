#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string getPermutation(int n, int k)
{
	int tmp[9] = { 1,2,3,4,5,6,7,8,9 };
	int mul[10] = {1};

	for (int i = 1; i < 10; i++)
		mul[i] = i*mul[i-1];

	string str;
	int anch = 0;
	k--;
	for (int i = n; i > 0; i--)
	{
		int index =k / mul[i - 1];
		k %= mul[i - 1];
		str.push_back(tmp[anch + index] + '0');
		swap(tmp[anch + index], tmp[anch]);
		//进行移动保证大小顺序相同
		while (index > 1) { swap(tmp[index + anch], tmp[index + anch - 1]); index--; }
		anch++;
	}

	return str;
}


int main()
{

	cout << getPermutation(9,54494)<<endl;
	getchar();
	return 0;
}


