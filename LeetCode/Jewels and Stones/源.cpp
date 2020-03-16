#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int hashTable[72]{0};

int getHash(char n)
{
	return n - 65;
}

int numJewelsInStones(string J, string S) {

	memset(hashTable,0,sizeof(int)*72);
	
	int num = 0;

	for (int i = 0; i < S.size(); i++)
	{
		hashTable[getHash(S[i])]++;
	}

	for (int i = 0; i < J.size(); i++)
	{
		num += hashTable[getHash(J[i])];
	}

	return num;

}


int main()
{
	string J = "z";
	string S = "ZZ";

	int num = numJewelsInStones(J,S);
	cout << num<<endl;

		
	getchar();
	return 0;
}