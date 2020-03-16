#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* rotateRight(ListNode* head, int k) {

	if (head == nullptr) return nullptr;

	int n = 1;
	ListNode* pnode = head;
	ListNode* ppnode = head;
	while (n != (k+1))
	{
		while (n != (k+1)&&ppnode->next != nullptr)
		{
			ppnode = ppnode->next;
			n++;
		}
		if (k%n == 0) return head;
		if (n != (k+1))
		{
			k = k%n;
			if (k == 0) return head;
			n = 1;
			ppnode = head;
		}
	}


	while (ppnode->next != nullptr)
	{
		pnode = pnode->next;
		ppnode = ppnode->next;
	}

	ppnode->next = head;
	ListNode*node = pnode;
	pnode = pnode->next;
	node->next = nullptr;
	return pnode;
}

int main()
{

	

	getchar();
	return 0;
}