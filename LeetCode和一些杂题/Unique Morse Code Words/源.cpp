#include<vector>
#include<iostream>

using namespace std;


int uniqueMorseRepresentations(vector<string>& words) {

	static string morse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
		"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--"
		,"-..-","-.--","--.." };


	for (int i = 0; i < words.size(); i++)
	{
		string str = "";
		for (int j = 0; j < words[i].size(); j++)
		{
			str += morse[words[i][j] - 97];
		}
		words[i] = str;
	}

	for (int i = 0; i < words.size(); i++)
	{
		printf(words[i].c_str());
		cout << endl;
	}

	for (int i = 0; i < words.size(); i++)
	{
		for (int j = i+1; j < words.size(); j++) {
			if (words[i] == words[j])
			{
				words.erase(words.begin()+j);
				j--;
			}
		}
	}

	return words.size();
}

int main()
{
	vector<string> list = { "rwjje","aittjje","auyyn","lqtktn","lmjwn" };

	int num = uniqueMorseRepresentations(list);

	printf("公有  %d\n",num);

	getchar();
	return 0;
}

/*
更好的解决方案
int uniqueMorseRepresentations(vector<string>& words) {
unordered_map<string, int> code;
vector<string> morsecodes = {".-","-...","-.-.","-..",".","..-.",
"--.","....","..",".---","-.-",".-..",
"--","-.","---",".--.","--.-",".-.","...",
"-","..-","...-",".--","-..-","-.--","--.."};
for(string s: words)
{
string tmp = "";
for(char c: s)
tmp += morsecodes[c-97];
code[tmp]++;
}

return code.size();
}
*/