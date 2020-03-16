#include<iostream>
using namespace std;


class Node{
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

Node *connect(Node* root) {

	if (root == nullptr) return root;

	Node *p = root;

	while (p != nullptr)
	{
		Node* pp = p;
		Node* node = nullptr;
		p = nullptr;
		while (pp != nullptr)
		{
			if (pp->left != nullptr)
			{
				if (node != nullptr) node->next = pp->left;
				node = pp->left;
			}
			if (p == nullptr&&node != nullptr) p = node;
			if (pp->right != nullptr)
			{
				if (node != nullptr) node->next = pp->right;
				node = pp->right;
			}
			if (p == nullptr&&node != nullptr) p = node;
			pp = pp->next;
		}

	}

	return root;
}

int main()
{

	getchar();
	return 0;
}