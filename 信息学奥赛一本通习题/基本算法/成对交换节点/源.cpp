#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* swapPairs(ListNode* head) {

	if (head == nullptr) return head;
	if (head->next == nullptr) return head;

	ListNode* p = head;
	ListNode* pp = head->next;
	ListNode* newHead = pp;

	while (pp != nullptr)
	{
		ListNode* tmp = pp->next;
		pp->next = p;
		p->next = tmp;
		
		if (tmp == nullptr||tmp->next == nullptr) break;

		p->next = tmp->next;
		p = tmp;
		pp = tmp->next;
	}

	return newHead;
}


int main()
{


	getchar();
	return 0;
}

