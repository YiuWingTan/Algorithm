#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};



TreeNode* createTree(ListNode* head, ListNode*tail, int len)
{
	if (len < 1) return nullptr;
	if (len == 1)
	{
		return new TreeNode(head->val);
	}
	ListNode* mid = head;
	ListNode* back = head;
	int ans = (float)len / 2 + 0.5f;
	
	for (int i = 1; i < ans; i++)
	{
		back = mid;
		mid = mid->next;
	}

	TreeNode* node = new TreeNode(mid->val);
	node->left = createTree(head,back,len/2-1);
	node->right = createTree(mid->next,tail,len - len/2);
	return node;

}

TreeNode* sortedListToBST(ListNode* head) {

	if (head == nullptr) return nullptr;

	int len = 1;
	ListNode* node = head;
	while (node->next != nullptr)
	{
		node = node->next;
		len++;
	}

	return createTree(head,node,len);

}
