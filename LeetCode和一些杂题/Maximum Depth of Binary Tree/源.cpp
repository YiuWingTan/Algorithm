#include<iostream>
#include<queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


int maxDepth(TreeNode* root) {

	if (root == nullptr)return 0;

	TreeNode* node;
	int len = 0;
	queue<TreeNode*> que;
	que.push(root);
	int count = 1;

	while (!que.empty())
	{
		node = que.front(); que.pop();

		if (node->left != nullptr) que.push(node->left);
		if (node->right != nullptr) que.push(node->right);

		if ((--count) == 0)
		{
			len++;
			count = que.size();
		}
	}
	return len;
}


int main()
{



	getchar();
	return 0;
}
