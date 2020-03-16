/*
 z字型打印二叉树
*/
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

	if (root == nullptr) return{};

	vector<vector<int>> result;//结果
	vector<int> tmp;
	stack<TreeNode*> order;//正序栈
	stack<TreeNode*> inOrder;//逆序栈
	order.push(root);
	TreeNode*node;

	while (!order.empty()||!inOrder.empty())
	{
		if (order.empty())
		{
			
			while (!inOrder.empty())
			{
				node = inOrder.top();
				tmp.push_back(node->val);
				inOrder.pop();
				if (node->right != nullptr) order.push(node->right);
				if (node->left != nullptr) order.push(node->left);
			}
			result.push_back(tmp);
		}
		else
		{
			while (!order.empty())
			{
				node = order.top();
				tmp.push_back(node->val);
				order.pop();
				if (node->left != nullptr) inOrder.push(node->left);
				if (node->right != nullptr) inOrder.push(node->right);
			}
			result.push_back(tmp);
		}
		tmp.clear();

	}

	return result;
}


int main()
{

	getchar();
	return 0;
}