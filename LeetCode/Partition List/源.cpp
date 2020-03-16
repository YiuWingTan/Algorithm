#include<iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* partition(ListNode* head, int x) {

	if (head == NULL || head->next == NULL) return head;


	ListNode *h = nullptr;
	ListNode *t = nullptr;

	ListNode node(INT_MAX);
	node.next = head;
	ListNode *p = &node;
	ListNode *pp = head;

	while (pp != nullptr)
	{
		if (pp->val < x)
		{
			p->next = pp->next;
			pp->next = nullptr;
			if (h == nullptr) h = t = pp;
			else {
				t->next = pp;
				t = pp;
			}
			pp = p->next;
		}
		else
		{
			p = pp;
			pp = pp->next;
		}
	}

	t->next = node.next;

	return h;
}

//½â·¨¶þ
ListNode* partition2(ListNode* head, int x)
{
	if (head == NULL || head->next == NULL) return head;

	ListNode node(INT_MAX);
	node.next = head;
	ListNode *h = &node;
	ListNode *p = h;
	ListNode *pp =head;
	ListNode *mid;

	while (pp != nullptr)
	{
		if (pp->val < x)
		{
			mid = pp->next;
			pp->next = p->next;
			p->next = pp;
			pp = mid;
			p = p->next;
		}
		else pp = pp->next;

	}

	return node.next;
}


int main()
{
	

	getchar();
	return 0;
}