#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


int minDepth(TreeNode* root) {

	if (root == nullptr) return 0;

	queue<TreeNode*> que;
	int num = 1;
	int height = 1;
	que.push(root);
	while (!que.empty())
	{
		auto node = que.front(); que.pop();

		if (node->left == nullptr&& node->right == nullptr) return height;
		if(node->left!=nullptr)
		que.push(node->left);
		if(node->right!=nullptr)
		que.push(node->right);
		if (--num == 0)
		{
			height++;
			num = que.size();
		}
	}
	return height;
}

int main()
{


	getchar();
	return 0;
}
