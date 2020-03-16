#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

//�ⷨһ
/*
TreeNode* insertIntoBST(TreeNode* root, int val) {

	if (root == nullptr) return new TreeNode(val);

	if (root->val > val) root->left = insertIntoBST(root->left,val);
	else root->right = insertIntoBST(root->right,val);
	return root;

}
*/

void find(TreeNode*node,int val)
{
	if (node->val > val)
		if (node->left == nullptr) {
			node->left = new TreeNode(val);
			return;
		}
		else find(node->left,val);
	else {
		if (node->right == nullptr)
		{
			node->right = new TreeNode(val);
			return;
		}
		else find(node->right,val);
	}
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
	
	if (root == nullptr) return new TreeNode(val);

	find(root,val);

	return root;

}


int main()
{


	getchar();
	return 0;
}
