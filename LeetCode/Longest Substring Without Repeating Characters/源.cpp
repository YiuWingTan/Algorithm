#include<iostream>
#include<cstring>
#include<string>
using namespace std;
using  std::string;


struct Node
{
	int start;
	int end;
	int num;

	Node(int s ,int e):start(s),end(e),num(0)
	{

	}

	Node() :start(0), end(0),num(1)
	{

	}
};

Node*list ;

int getLongest(string &str,int s, int e)
{
	list[s].end = s;
	list[s].start = s;
	list[s].num = 1;
	int m = s;
	//cout << "s: "<<s<<" e: "<<e<<endl;
	int n;
	int start;
	int end;
	for (int i = m + 1; i <= e; i++, m++)
	{
		
		int n = list[m].num;
		int start = list[m].start;
		int end = list[m].end;
		
		//����һλ
		if (i ==list[m].end + 1)
		{
			//cout << "Yes\n";
			int j = 0;
			bool isFind = false;
			for (j; j < n; j++)
			{
				if (str[i] == str[end - j]) { isFind = true; break; }
			}

			//���ظ�
			if (isFind)
			{
				//���ǰnλ
				//cout << "kakak";
				if (getLongest(str, i - n + 1, i) == n)
				{
					list[i].start = i - n + 1;
					list[i].end = i;
				}
				else
				{
					list[i].start = start;
					list[i].end = end;
				}
				list[i].num = n;
			}
			//û���ظ�
			else
			{
				//cout << "ddd\n";
				list[i].start = start;
				list[i].end = i;
				list[i].num = n + 1;
			}
		}
		//���Ŷ�λ
		else
		{
			if (getLongest(str, i - n + 1, i) == n)
			{
				//��⵽�����
				list[i].start = i - n + 1;
				list[i].end = i;
				list[i].num = n;
			}
			else

			{
				//û��⵽�����
				list[i].start = start;
				list[i].end = end;
				list[i].num = n;
			}
		}

	}

	return list[e].num;
}

int longestSubString(string s)
{
	list = new Node[s.size()];
	return getLongest(s,0,s.size()-1);
}

int main()
{
	string s;

	getline(cin, s);

	int n = longestSubString(s);

	cout << "����ִ��� "<<n<<" ��"<<endl;

	getchar();

	return 0;
}

