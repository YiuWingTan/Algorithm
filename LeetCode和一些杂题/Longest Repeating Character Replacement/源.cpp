#include<iostream>
#include<vector>

using namespace std;

int max(int i,int j)
{
	return i > j ? i : j;
}

/*
ʹ�û�������
*/
int characterReplacement(string s, int k) {

	//������ȷ�����ַ�������ȫ�ظ����ַ���
	
	if (s.size() == 0||s.size()<=k) return s.size();

	int maxCharCount= 0;
	int result = 0;
	int start = 0,end = 0;
	vector<int> tmp(26,0);

	for (end = 0; end < s.size(); end++)
	{
		tmp[s[end] - 'A']++;
		if (tmp[s[end] - 'A'] > maxCharCount) maxCharCount = tmp[s[end] - 'A'];

		while (end - start + 1 - maxCharCount > k)
		{
			//���ִ��и�����ͬ����������kʱ����ѭ�������������ڵ���߽���ǰ�ƶ�,
			//ע�⵱end == startʱ�ͻ��Զ����˳�ѭ����Ϊ��ʱmaxcharcount��ֵΪ1����k�Ǵ��ڵ���0��.

			tmp[s[start] - 'A']--;//���л������ڵ���߽���л���
			start++;

			//Ѱ�ҵ�ǰ�ִ������ֵ
			maxCharCount = 0;
			for (int i = 0; i < 26; i++)
			{
				if (maxCharCount < tmp[i]) maxCharCount = tmp[i];
			}

		}
		
		result = max(result,end - start+1);
	}

	return result;
}

//���ܲ���
void text1()
{
	string str = "AAAA";
	int k = 0;

	cout << "��󳤶�Ϊ"<< characterReplacement(str,k)<<endl;
}

//�߽����
void text2()
{

}


int main()
{

	text1();

	getchar();
	return 0;
}
