#include<iostream>
#include<vector>


using namespace std;

struct ListNode
{
	int val;
	ListNode*next;
};

ListNode * createList(vector<int>&arr)
{
	if (arr.size() == 0) return nullptr;

	ListNode *head = new ListNode;
	head->val = arr[0];
	ListNode *node = head;

	for (int i = 0; i < arr.size(); i++)
	{
		node->next = new ListNode();
		node = node->next;
		node->val = arr[i];
	}

	return head;
}

ListNode* deleteList(ListNode*node)
{
	if (node == nullptr) return nullptr;
	ListNode*x = node;
	while (node != nullptr)
	{
		x = node->next;
		delete node;
		node = x;
	}
}

ListNode* solve()
{

}


void text1()
{
	vector<int> arr1 = {};
	auto l1 = createList(arr1);

	vector<int> arr2 = {};
	auto l2 = createList(arr2);
	int n = 2;
	


}

void text2()
{

}


int main()
{


	getchar();
	return 0;
}


