#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {

	if (head == nullptr||head->next == nullptr) return head;
	ListNode watch = ListNode(INT_MAX);
	watch.next = head;
	ListNode* p = head;
	ListNode* pp = p->next;
	ListNode *n = &watch;

	while (pp != nullptr)
	{
		if (p->val == pp->val)
		{
			while (pp != nullptr&&p->val == pp->val) pp = pp->next;
			n->next = pp;
			p = pp;
			if (p != nullptr) pp = pp->next;
		}
		else
		{
			n = p;
			p = pp;
			pp = pp->next;
		}
		
		
	}

	return watch.next;
}


int main()
{

	getchar();
	return 0;
}