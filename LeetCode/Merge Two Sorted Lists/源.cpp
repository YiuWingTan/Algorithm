/*
	难度 简单 主题 链表
*/

#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	ListNode *f = l1;
	ListNode *s = l2;
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	while (f != NULL || s != NULL)
	{
		if (f == NULL)
		{
			p->next = s;
			s = s->next;
		}
		else if (s == NULL)
		{
			p->next = f;
			f = f->next;
		}
		else if(f->val > s->val)
		{
			p->next = s;
			s = s->next;
		}
		else
		{
			p->next = f;
			f = f->next;
		}
		p = p->next;
	}

	return head->next;
}

int main()
{

}
