#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

bool judge(TreeNode* node,int *depth)
{
	if (node == nullptr) return true;

	int left = 0;
	int right = 0;

	if (judge(node->left, &left) && judge(node->right, &right))
	{
		if (abs(left - right) <= 1)
		{
			*depth = (left > right ? left : right)+1;
			return true;
		}
	}
	
	return false;
}

bool isBalanced(TreeNode* root) {

	return isBalanced(root);

}

int main() {



}

