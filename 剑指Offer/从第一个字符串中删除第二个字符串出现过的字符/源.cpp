#include<iostream>
#include<string>

using namespace std;


string deleteCharFromString(const string &str,const string &tar)
{
	if (tar.size() == 0||str.size() == 0) return str;

	string result = "";
	int hash[256] = {0};


	for (int i = 0; i < str.size(); i++)
		hash[str[i]]++;
	for (int i = 0; i < tar.size(); i++)
		hash[tar[i]] = 0;
	for (int i = 0; i < str.size(); i++)
		if (hash[str[i]] != 0) result += str[i];
	return result;
}


void text1()
{
	string str = "faggdsfgds";
	string t = "";
	string result = deleteCharFromString(str,t);
	cout << str << "   " << t << "  :" << result << endl<<endl;

}
void text2()
{
	string str = "";
	string t = "65fg4df4gdf1dnhd";
	string result = deleteCharFromString(str, t);
	cout << str << "   " << t << "  :" << result << endl << endl;
}
void text3()
{
	string str = "We are students";
	string t = "aeiou";
	string result = deleteCharFromString(str, t);
	cout << str << "   " << t << "  :" << result << endl << endl;
}
void text4()
{
	string str = "hellow";
	string t = "helow";
	string result = deleteCharFromString(str, t);
	cout << str << "   " << t << "  :" << result << endl << endl;
}


int main()
{
	text1();
	text2();
	text3();
	text4();

	getchar();
	return 0;

}