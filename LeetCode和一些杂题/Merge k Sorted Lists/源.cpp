/*
	难度 困难 主题 分治法 ，链表 堆栈
*/

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

	ListNode *p = NULL;
	ListNode *pp = NULL;
	ListNode *node = NULL;
	ListNode *head;
	while (lists.size() >1)
	{
		p = lists[0];
		pp = lists[1];
		node = new ListNode(0);
		head = node;


		while (p != NULL || pp != NULL)
		{
			if (p == NULL)
			{
				node->next = pp;
				pp = pp->next;
			}
			else if (pp == NULL)
			{
				node->next = p;
				p = p->next;
			}
			else if (p->val > pp->val)
			{
				node->next = pp;
				pp = pp->next;
			}
			else
			{
				node->next = p;
				p = p->next;
			}
			node = node->next;
			node->next = NULL;
		}
		
		lists.erase(lists.begin(),lists.begin()+2);
		printf("%d\n", lists.size());

		lists.push_back(head->next);
	}

	return lists[0];
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

void showList(ListNode *p)
{
	if (p == NULL) return;
	while (p != NULL)
	{
		printf("%d-",p->val);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	vector<ListNode*> lists;
	vector<int> nums = { 1,4,5 };
	ListNode *first = CreateList(nums);
	nums = { 1,3,4 };
	ListNode*second = CreateList(nums);
	nums = { 2,6 };
	ListNode *third = CreateList(nums);
	showList(first);
	showList(second);
	showList(third);
	lists.push_back(first);
	lists.push_back(second);
	lists.push_back(third);

	ListNode *p = mergeKLists(lists);
	showList(p);

	//vector<int> nums{1,2,3,6,5,4};
	
	getchar();
	return 0;
}