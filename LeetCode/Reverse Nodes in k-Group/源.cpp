/*
	难度 困难 主题
*/

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k <= 1) return head;
	int n = 0;

	bool isFind = false;
	ListNode *st = head;
	ListNode *end = head;
	ListNode *first = head;
	ListNode *pend = NULL;

	while (end != NULL)
	{
		n = 1;
		printf("哈哈哈");
		while (n != k&&end!=NULL)
		{
			end = end->next;
			n++;
		}
		if (end == NULL) break;
		if (!isFind) { isFind = true; first = end; }

		ListNode *p = st->next;
		ListNode *pp = p->next;
		ListNode *s = st;
		while (true)
		{
			p->next = s;
			if (p == end) break;
			s = p;
			p = pp;
			pp = pp->next;
		}
		if (pend != NULL) { pend->next = end; }
		pend = st;
		st->next = pp;
		end = pp;
		st = end;
		
	}

	return first;
}

ListNode* CreateList(vector<int> &nums)
{
	ListNode *head;
	ListNode *p = new ListNode(nums[0]);
	head = p;
	for (int i = 1; i < nums.size(); i++)
	{
		ListNode *node = new ListNode(nums[i]);
		p->next = node;
		p = p->next;
	}
	return head;
}

void ShowList(ListNode *p)
{
	if (p == NULL) return;
	while (p != NULL)
	{
		printf("%d-", p->val);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	vector<int> nums{ 1,2 };
	ListNode *node = CreateList(nums);
	ShowList(node);

	ListNode *p = reverseKGroup(node,3);
	ShowList(p);


	getchar();
	return 0;
}