#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


int findBottomLeftValue(TreeNode* root) {

	if (root == nullptr) {
		return INT_MIN;
	}

	queue<TreeNode*> que;
	int left = root->val;
	que.push(root);
	int count = 1;

	while (!que.empty())
	{
		auto node = que.front(); que.pop();

		if (node->left != nullptr) que.push(node->left);
		if (node->right != nullptr) que.push(node->right);
		count--;

		if (count == 0)
		{
			left = que.front()->val;
			count = que.size();
		}
	}
	return left;
}

