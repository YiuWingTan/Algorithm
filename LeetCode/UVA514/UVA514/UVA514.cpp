// UVA514.cpp : 定义控制台应用程序的入口点。
//


#include"Dequeue.h"
#include<string>
#include<iostream>
#include<map>
#include<sstream>
using namespace std;

struct Program
{
	Dequeue<string> pro;

	int number;

	bool isLock;

	Program()
	{
		isLock = false;
	}
};

void ActProgram(Program);

Dequeue<Program> stopQ;

Dequeue<Program> actionQ;

map<string, int> vars;

bool hasLock = false;
int n, t1, t2, t3, t4, t5, Q;
int main()
{
	string input;

	getline(cin,input);

	int a[7]{0,0,0,0,0,0,0};

		int m = 1,i =0;

	for (int j = 0; j < input.size(); j++,m++)
	{
		if (input[j] == ' '||input[j] == '\n'||j == input.size()-1)
		{
			if (j == input.size() - 1)
			{
				j++;
				m++;
			}
			int n = 1;

			for (int k = 1; k < m; k++)
			{
				a[i] += (int(input[j - k])-48)*n;
				n *= 10;
			}
			m = 0;
			i++;
		}
	}

	for (int c = 0; c < 7; c++)
		cout << a[c]<<"  ";

	cout << endl;
	n = a[0];
	t1 = a[1];
	t2 = a[2];
	t3 = a[3];
	t4 = a[4];
	t5 = a[5];
	Q = a[6];

	Program *p = new Program[n];
	string str;
	int num = 0;

	while (num < n)
	{
		getline(cin,str);
		p[num].pro.Push_Back(str);

		if (str == "end") {
			p[num].number = num + 1;
			actionQ.Push_Back(p[num]);
			num++;
			
		}

		str = "";
	}
	/*cout << "获取的程序为";
	for (int i = 0; i < n; i++)
	{
		cout << i+1<<"号程序:\n";
		while (!p[i].pro.isEmpty())
		{
			cout << p[i].pro.Pop_Front() << endl;
		}
	}*/
	


	while (!actionQ.isEmpty())
	{
		ActProgram(actionQ.Pop_Front());
	}
	

	system("pause");
}
//执行一条语句
void ActProgram(Program p)
{
	int time = 0;

	bool islock = false;

	while (!p.pro.isEmpty())
	{
		string str = p.pro.Pop_Front();
		//cout << str<<endl;
		Dequeue<string> q;
		string n = "";

		//获取一个命令块
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				q.Push_Back(n);
				n = "";
			}
			else if (i == str.size() - 1)
			{
				n += str[i];
				q.Push_Back(n);
				n = "";
			}
			else
			{
				n += str[i];
			}
		}

		//运行这个命令
		
		string s = q.Pop_Front();

		if (s == "print") {
			time += t2;

			string name = q.Pop_Front();

			int v = vars[name];

			cout << p.number<<": "<<v<<endl;

				
		}
		else if (s == "lock")
		{
			if (hasLock)
			{
				p.pro.Push_Front("lock");

				stopQ.Push_Back(p);

				return;
			}
			time += t3;
			islock = true;
			hasLock = true;
			p.isLock = true;
				
		}
		else if (s == "unlock")
		{
			time += t4;
			p.isLock = false;
			hasLock = false;
			if (!stopQ.isEmpty())
			{
				Program r = stopQ.Pop_Front();

				actionQ.Push_Front(r);
			}
		}
		else if (s == "end")
		{
			time += t5;

			return;
		}
		else
		{
			time += t1;
			string name = s;
			int value;
			q.Pop_Front();

			string v = q.Pop_Front();
			stringstream  ss;
			ss << v;
			ss >> value;

			if (vars.find("name") == vars.end())
			{
				//不存在这个 键

				vars[name] = value;
			}
			else
			{
				vars[name] = value;
			}

			
		}

		if (time >= Q) {
			break;
		}
	}

	
	actionQ.Push_Back(p);
}

