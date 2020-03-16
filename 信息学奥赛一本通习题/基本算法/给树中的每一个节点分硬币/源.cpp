#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int result = 0;




int helper(TreeNode* node)
{
	if (node == nullptr) return 0;

	int left = helper(node->left);
	int right = helper(node->right);

	int res = abs(left) + abs(right) + node->val - 1;

	result += res;

	return result;

}

int distributeCoins(TreeNode* root) {

	if (root == nullptr) return;
	helper(root);
	return result;

}



