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


	ListNode *p = head;
	ListNode *pp = p->next;

	while (pp != nullptr)
	{
		if (p->val == pp->val)
		{
			p->next = pp->next;
			delete pp;
			pp = p->next;
		}
		else
		{
			p = pp;
			pp = pp->next;
		}
	}

	return head;
}


int main()
{


	getchar();
	return 0;
}
