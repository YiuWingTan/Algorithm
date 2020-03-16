#include<iostream>
#include<vector>
#include<string>
using namespace std;

//��ȡ�ַ�
char getFirstApperanceChar(string& str)
{
	if (str.size() == 0) return ' ';

	int count[256] = {0};//����256��Ԫ�ص�����䵱��ϣ��
	
	for (int i = 0; i < str.size(); i++)
	{
		count[str[i]]++;
	}
	int i;
	for ( i = 0; i < str.size(); i++)
	{
		if (count[str[i]] == 1) break;
	}
	return i == str.size() ? ' ' : str[i];

}

void text1()
{
	string str = "1111";
	char c = getFirstApperanceChar(str);

	if(c != ' ')
	printf("%s �е�һ��ֻ����һ�ε��ַ���%c\n", str.c_str(), c);
	else printf("%s��û��ֻ����һ�ε��ַ�\n",str.c_str());
	cout << endl;
}
void text2()
{
	string str = "sdfagdfsgf";
	char c = getFirstApperanceChar(str);

	if (c != ' ')
		printf("%s �е�һ��ֻ����һ�ε��ַ���%c\n", str.c_str(), c);
	else printf("%s��û��ֻ����һ�ε��ַ�\n", str.c_str());
	cout << endl;
}
void text3()
{
	string str = "";
	char c = getFirstApperanceChar(str);

	if (c != ' ')
		printf("%s �е�һ��ֻ����һ�ε��ַ���%c\n", str.c_str(), c);
	else printf("%s��û��ֻ����һ�ε��ַ�\n", str.c_str());
	cout << endl;
}
void text4()
{
	string str = "dfa;lfafbk3165dsfs";
	char c = getFirstApperanceChar(str);

	if (c != ' ')
		printf("%s �е�һ��ֻ����һ�ε��ַ���%c\n", str.c_str(), c);
	else printf("%s��û��ֻ����һ�ε��ַ�\n", str.c_str());
	cout << endl;
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
