#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};


//解法一： 宽度优先搜索
Node* connect(Node* root) {

	if (root == nullptr) return root;

	queue<Node*> que;
	que.push(root);
	int count = 1;

	while (!que.empty())
	{
		auto node = que.front(); que.pop();
		if(node->left!=nullptr)
			que.push(node->left);
		if (node->right != nullptr)
			que.push(node->right);

		if (count!=1) node->next = que.front();

		if (--count == 0)
		{
			count = que.size();
		}
	}
	return root;
}

//解法二 ：迭代
Node* connect2(Node*root)
{
	if (root == nullptr) return root;

	Node* p = root;
	
	while (p->left != nullptr)
	{
		Node*pp = p;
		while (pp != nullptr)
		{
			pp->left->next = pp->right;
			if (pp->next != nullptr) pp->right->next = pp->next->left;
			pp = pp->next;
		}

		p = p->left;
	}

	return root;
}

int main()
{

	getchar();
	return 0;
}
