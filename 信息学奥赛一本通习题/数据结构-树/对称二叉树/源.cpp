#include<iostream>
#include<string>
using namespace std;

struct Node
{
	Node() { left = right = 0; }
	int left, right;
};

Node nodes[1000];

int main()
{
	bool result = true;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		int left = i * 2 + 1;
		int right = i * 2 + 2;

		if (left < str.size())
		{
			nodes[i].left = str[left] == '#' ? 0 : left;
		}

		if (right < str.size())
		{
			nodes[i].right = str[right] == '#' ? 0 : right;
		}
		
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (nodes[i].left == 0 && nodes[i].right != 0)
		{
			result = false;
			break;
		}

		if (nodes[i].left != 0 && nodes[i].right == 0)
		{
			result = false;
			break;
		}
	}


	if (result) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}



