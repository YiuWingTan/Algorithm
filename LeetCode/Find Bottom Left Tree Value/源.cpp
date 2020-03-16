#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

/*
解法一：使用dfs
解法二 使用队列(bfs)
*/

int num = -1;
int n;
void findLeft(TreeNode*node,int depth)
{
	if (node == nullptr) return;

	findLeft(node->left,depth+1);
	findLeft(node->right,depth+1);

	if (depth > num)
	{
		n = node->val;
		num = depth;
	}
}

int findLeft(TreeNode*node)
{
	int result = node->val;
	int count = 1;
	queue<TreeNode*> que;
	
	que.push(node);


	while (!que.empty())
	{
		auto node = que.front();
		que.pop();

		if (node->left != nullptr) que.push(node->left);
		if (node->right != nullptr) que.push(node->right);

		if (--count == 0)
		{
			count = que.size();
			if (que.empty()) break;
			result = que.front()->val;
		}

	}

	return result;

}

int findBottomLeftValue(TreeNode* root) {
	
	if (root == nullptr) return 0;
	
	return findLeft(root);

}

int main()
{


	getchar();
	return 0;
}

