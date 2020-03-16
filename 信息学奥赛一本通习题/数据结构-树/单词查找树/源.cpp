
/*

解决思路
1.使用建树的方案
2.不进行建树,使用单词长度差和字典序的概念
首先要对建树的过程有一个了解。对于当前被处理的单词和当前树：在根结点的子结点中找单词的第一位字母，若存在则进而在该结点的子结点中寻找第二位……如此下去直到单词结束，
即不需要在该树中添加结点；或单词的第n位不能被找到，即将单词的第n位及其后的字母依次加入单词查找树中去。但，本问题只是问你结点总数，而非建树方案，
且有32K文件，所以应该考虑能不能不通过建树就直接算出结点数？为了说明问题的本质，我们给出一个定义：一个单词相对于另一个单词的差：设单词1的长度为L
，且与单词2从第N位开始不一致，则说单词1相对于单词2的差为L-N+1，这是描述单词相似程度的量。可见，将一个单词加入单词树的时候，须加入的结点数等于该单词树中已有单词的差的最小值。
单词的字典顺序排列后的序列则具有类似的特性，即在一个字典顺序序列中，第m个单词相对于第m-1个单词的差必定是它对于前m-1个单词的差中最小的。于是，得出建树的等效算法：


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

//删除树
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

