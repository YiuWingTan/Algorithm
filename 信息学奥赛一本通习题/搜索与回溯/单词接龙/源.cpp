

/*

1220�����ʽ���

ʱ������: 1000 ms         �ڴ�����: 65536 KB
�ύ��: 2834     ͨ����: 1607
����Ŀ������
���ʽ�����һ�������Ǿ�����ĳ�����������Ƶ���Ϸ������������֪һ�鵥�ʣ��Ҹ���һ����ͷ����ĸ��Ҫ����������ĸ��ͷ����ġ�������ÿ�����ʶ�����ڡ������г������Σ�����������������ʱ�����غϲ��ֺ�Ϊһ���֣�����beast��astonish������ӳ�һ�������Ϊbeastonish���������ڵ������ֲ��ܴ��ڰ�����ϵ������at��atide�䲻��������

�����롿
����ĵ�һ��Ϊһ������������n(n��20)��ʾ������������n��ÿ����һ�����ʣ�ֻ���д�д��Сд��ĸ�����Ȳ�����20������������һ��Ϊһ�������ַ�����ʾ��������ͷ����ĸ������Լٶ��Դ���ĸ��ͷ�ġ�����һ�����ڡ�

�������
ֻ������Դ���ĸ��ͷ����ġ������ĳ��ȡ�

������������
5
at
touch
cheat
choose
tact
a
�����������
23


���㷨������
	ע���ҵ�����С�ص�����

*/

#include<iostream>
#include<string>
using namespace std;
int k;
int maxlen;
int isused[21];
string words[21];

inline int max(int i,int j)
{
	return i > j ? i : j;
}

int link(string&tar,string &src,int len)
{
	for (int i = len-1; i >=0; i--)
	{
		if (tar[i] == src[0]) {

			//�鿴�ܷ�������
			int j = 0;
			for (; i+j<len && tar[j + i] == src[j]; j++);
			if (i + j == len) return i ==0?0:j;
		}
	}
	return 0;
}


void klondike(string&tar,int len)
{
	if (len > maxlen) maxlen = len;

	//Ѱ�ҵ���
	for (int i = 0; i < k; i++)
	{
		if (isused[i] == 2) continue;

		int n = link(tar,words[i],len);

		if (n == 0) continue;

		for (int j = 0; j < words[i].size() - n; j++)
			tar[j + len] = words[i][j+n];

		isused[i]++;

		

		klondike(tar,len+ words[i].size() - n);

		isused[i]--;

	}


}


int main()
{
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> words[i];
	}

	char w;
	cin >> w;

	string tar;
	tar.resize(400);
	for (int i = 0; i < k; i++)
	{
		if (words[i][0] == w)
		{
			
			for (int j = 0; j < words[i].size(); j++)
				tar[j] = words[i][j];
			isused[i]++;
			klondike(tar,words[i].size());
			isused[i]--;
		}
	}

	cout << maxlen << endl;

	return 0;
}








