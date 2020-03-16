#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

bool isBalanced(TreeNode* node)
{

}


bool isBalanced(TreeNode* root) {

	if (root == nullptr) return true;

}