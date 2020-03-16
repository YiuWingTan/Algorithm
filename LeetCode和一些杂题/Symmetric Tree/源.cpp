#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

bool judege(TreeNode*p,TreeNode*q)
{
	if (p == nullptr&&q == nullptr) return true;
	if (p == nullptr || q == nullptr) return false;

	if (p->val != q->val) return false;

	bool result = false;
	result &= judege(p->left, q->right);
	result &= judege(p->right,q->left);
	return result;
}

//¾µÏñÊ÷ÅÐ¶Ï
bool isSymmetric(TreeNode* root) {

	if (root == nullptr) return true;

	return judege(root->left,root->right);

}


int main()
{

	getchar();
	return 0;
}