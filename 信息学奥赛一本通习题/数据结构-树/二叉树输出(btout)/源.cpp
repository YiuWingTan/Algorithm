
/*
过于简单不做
*/



#include<iostream>
#include<string>

using namespace std;

struct Node
{
	Node()
	{
		right = left = NULL;
		n = 0;
	}

	char str;
	int n;
	Node*left,*right;
};

Node nodes[50];

Node* CreateNode()
{
	static int index = 0;

	return &nodes[index++];
}


Node* createTree(string&pre,string&mid,int a,int b,int c)
{
	if (a > b) return NULL;

	Node*node = CreateNode();
	node->str = pre[c];
	int i = a;
	for (; i <= b; i++)
		if (mid[i] == pre[c]) break;

	node->left = createTree(pre,mid,a,i-1,c+1);
	node->right = createTree(pre,mid,i+1,b,c+(i-a+1));

	if (node->left != NULL) node->n += node->left->n;
	if (node->right != NULL) node->n += node->right->n;
	if (node->left == NULL && node->right == NULL) node->n = 1;
	return node;
}

void show(Node* node)
{
	if (node == NULL) return;

	for (int i = 0; i < node->n; i++)
	{
		cout << node->str;
	}
	cout << endl;

	show(node->left);
	show(node->right);

}

int main()
{
	string pre, mid;
	cin >> pre >> mid;

	Node*root = createTree(pre,mid,0,mid.size()-1,0);

	show(root);

	return 0;
}


