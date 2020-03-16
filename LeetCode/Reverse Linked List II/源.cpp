#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseBetween(ListNode* head, int m, int n) {

	if (head == nullptr || head->next == nullptr || n - m == 0) return head;

	ListNode* check = nullptr;
	ListNode* p = head;
	ListNode* pp = nullptr;
	ListNode *mid = nullptr;

	int count = 1;
	if (m == 1)
	{
		check = head;
		pp = head->next;
		count++;
	}
	else
	{
		while (p != nullptr&&count > m - 1)
		{
			p = p->next;
			count++;
		}

		if (p != nullptr)
		{
			check = p;
			p = p->next;
			if (p != nullptr)
				pp = p->next;
			count = m + 1;
		}
	}
	
	while (pp != nullptr&&count != n + 1)
	{

		mid = pp->next;
		pp->next = p;
		p = pp;
		pp = mid;
		count++;
	}

	if (pp == nullptr&&check == head) { head->next = nullptr; return p; }
	
	if (pp == nullptr)
	{
		check->next->next = nullptr;
		check->next = p;
		return head;
	}

	if (check == head)
	{
		check->next = pp;
		return p;
	}

	if (check != nullptr&&check->next != nullptr&&check->next->next != nullptr&&p != nullptr)
	{
		check->next->next = pp;
		check->next = p;
		return head;
	}


	

}

int main()
{

}