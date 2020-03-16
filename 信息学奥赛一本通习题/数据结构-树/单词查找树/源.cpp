
/*

���˼·
1.ʹ�ý����ķ���
2.�����н���,ʹ�õ��ʳ��Ȳ���ֵ���ĸ���
����Ҫ�Խ����Ĺ�����һ���˽⡣���ڵ�ǰ������ĵ��ʺ͵�ǰ�����ڸ������ӽ�����ҵ��ʵĵ�һλ��ĸ��������������ڸý����ӽ����Ѱ�ҵڶ�λ���������ȥֱ�����ʽ�����
������Ҫ�ڸ�������ӽ�㣻�򵥴ʵĵ�nλ���ܱ��ҵ����������ʵĵ�nλ��������ĸ���μ��뵥�ʲ�������ȥ������������ֻ�����������������ǽ���������
����32K�ļ�������Ӧ�ÿ����ܲ��ܲ�ͨ��������ֱ������������Ϊ��˵������ı��ʣ����Ǹ���һ�����壺һ�������������һ�����ʵĲ�赥��1�ĳ���ΪL
�����뵥��2�ӵ�Nλ��ʼ��һ�£���˵����1����ڵ���2�Ĳ�ΪL-N+1�����������������Ƴ̶ȵ������ɼ�����һ�����ʼ��뵥������ʱ�������Ľ�������ڸõ����������е��ʵĲ����Сֵ��
���ʵ��ֵ�˳�����к��������������Ƶ����ԣ�����һ���ֵ�˳�������У���m����������ڵ�m-1�����ʵĲ�ض���������ǰm-1�����ʵĲ�����С�ġ����ǣ��ó������ĵ�Ч�㷨��


*/

#include<iostream>
#include<string>
using namespace std;

struct Node
{
	Node()
	{
		child = parent = bor = NULL;
	}

	char val;
	Node *child,*parent,*bor;


};

int ans = 1;

//ɾ����
void deleteTree(Node* node)
{
	if (node == NULL) return;

	Node* child = node->child;

	while (child != NULL)
	{
		deleteTree(child);
		child = child->bor;
	}

	delete node;
}

void createTree(string& str,int i,Node*parent)
{

	for (; i < str.size(); i++)
	{
		Node* node = new Node();
		node->val = str[i];

		node->bor = parent->child;
		parent->child = node;
		node->parent = parent;

		parent = node;
		ans++;
	}



}

int main()
{
	string str;
	Node* root = new Node();
	
	while (cin >> str)
	{
		int i = 0;
		Node* node = root->child;
		Node* last = root;

		while (i<str.size()&&node != NULL)
		{
			if (node->val == str[i])
			{
				last = node;
				node = node->child;
				i++;
				continue;
			}
			node = node->bor;
		}

		if (node == NULL) createTree(str,i,last);

	}


	cout << ans << endl;
	deleteTree(root);
	return 0;
}

