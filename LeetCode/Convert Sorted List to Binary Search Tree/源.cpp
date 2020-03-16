#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

TreeNode* createTree(ListNode* head, ListNode*tail, int len)
{
	int mark, n;

	if (len % 2 == 0) mark = len / 2;
	else mark = len / 2 + 1;
	n = mark;
	ListNode* node = head;
	ListNode* prev = head;
	while (node != nullptr&&mark>1)
	{
		mark--;
		if (mark <= 1) prev = node;
		node = node->next;

	}
	TreeNode *rn = new TreeNode(node->val);
	if (n - 1>1)
		rn->left = createTree(head, prev, n - 1);
	else if (n != 1)rn->left = new TreeNode(head->val);
	if (len - n>1)
		rn->right = createTree(node->next, tail, len - n);
	else if (len != 1) rn->right = new TreeNode(tail->val);
	return rn;
}

TreeNode* sortedListToBST(ListNode* head) {
	if (head == nullptr) return nullptr;
	ListNode*tail;
	ListNode *node = head;
	int len = 0;
	while (node != nullptr)
	{
		if (node->next == nullptr) tail = node;
		node = node->next;
		len++;
	}



	return createTree(head, tail, len);

}

void show(TreeNode*node)
{
	if (node != nullptr) return;
	show(node->left);
	cout << node->val<<"  ";
	show(node->right);
}


int main()
{


	getchar();
	return 0;
}

