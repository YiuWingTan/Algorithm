#include<iostream>
#include<vector>
#include<string>
using namespace std;


//��ȡ���-ʹ�ö�̬�滮���
int getLongest(string&arr)
{
	if (arr.size() == 0) return 0;
	int maxLen = 1;
	int dp = 1;
	vector<int> indexs;
	indexs.resize(26,-1);
	indexs[(arr[0] - 'a')] = 0;

	for (int i = 1; i < arr.size(); i++)
	{
		int index = indexs[(arr[i]) - 'a'];
		if (index != -1)
		{
			if ((i - index + 1) >(dp+1))
			{
				dp++;
			}
			else dp = (i - index);
		}
		else
		{
			dp++;
		}
		//��¼������ֵ�Ԫ�ص�����
		indexs[(arr[i]) - 'a'] = i;
		if (dp > maxLen) maxLen = dp;
	}
	return maxLen;
}

void text1()
{
	string str = "arabcarcf";
	cout << str<<"  ";
	printf("�����Ӵ��������Ϊ%d\n", getLongest(str));
}
void text2()
{
	string str = "a";
	cout << str << "  ";
	printf("�����Ӵ��������Ϊ%d\n", getLongest(str));
}
void text3()
{
	string str = "";
	cout << str << "  ";
	printf("�����Ӵ��������Ϊ%d\n", getLongest(str));
}
void text4()
{
	string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	cout << str << "  ";
	printf("�����Ӵ��������Ϊ%d\n", getLongest(str));
}
void text5()
{
	string str = "asdfghjkl";
	cout << str << "  ";
	printf("�����Ӵ��������Ϊ%d\n", getLongest(str));
}

int main()
{
	text1();
	text2();
	text3();
	text4();
	text5();

	getchar();
	return 0;
}