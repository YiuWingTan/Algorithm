/*
	难度 中等 主题 链表
*/
#include<iostream>
#include<vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* swapPairs(ListNode* head) {

	ListNode* p = head;
	if (p == NULL) return head;
	ListNode*pp = p->next;
	int val;
	while (pp != NULL)
	{
		val = pp->val;
		pp->val = p->val;
		p->val = val;

		p = pp->next;
		if (p == NULL) break;
		pp = p->next;
	}
	return head;
}

int main()
{

}