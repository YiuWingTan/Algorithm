/*
	难度 中等 主题 链表 双指针
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

	ListNode *p = head;
	ListNode *pp = p;

	int i = 0;
	for (; i < n&&pp->next!=NULL; i++)
	{
		pp = pp->next;
	}

	if (i != n) return head;
	if (i == n - 1) return head->next;

	while (pp->next != NULL)
	{
		pp = pp->next;
		p = p->next;
	}

	p->next = p->next->next;

	return head;

}

int main()
{

}