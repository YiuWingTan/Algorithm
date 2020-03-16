
#include<iostream>
#include<string>
using namespace std;

string delNum(string&str,int k)
{
	if (k == str.size()) return "";
	string re;

	int w = 0;
	
	while (w < k)
	{
		int i = 0,prev=0;

		while (i < str.size() && str[i] == '.')i++;
		prev = i;

		//�ǵ�����ʱ�����
		while (i<str.size())
		{
			prev = i;
			++i;
			while (i < str.size() && str[i] == '.')i++;

			if (str[i] < str[prev]) break;
			
		}

		
		str[prev] = '.';
		w++;

	}

	//��������Ƴ�
	int c = 0;
	while (c < str.size() && (str[c] == '0'||str[c] == '.')) c++;

	//���𰸸��Ƶ�re��
	for (int i = c; i < str.size(); i++)
	{
		if (str[i] != '.')
			re.push_back(str[i]);
	}
	return re;
}

int main()
{
	int n;
	string str;

	cin >> str;
	cin >> n;


	cout << delNum(str,n)<<endl;



	return 0;
}




