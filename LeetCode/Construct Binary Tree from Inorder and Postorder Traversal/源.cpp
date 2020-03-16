
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* create(vector<int>&postorder, vector<int>&inorder, int lo, int mid, int hi, int begin)
{
	TreeNode* node = new TreeNode(inorder[mid]);
	int root;
	int i;
	if (mid < hi)
	{
		root = postorder[begin -1];
		for (i = mid + 1; i <= hi&&root != inorder[i]; i++);
		node->right = create(postorder, inorder, mid + 1, i, hi, begin - 1);
	}
	if (mid > lo)
	{
		root = postorder[begin -(hi - mid)];
		for (i = mid - 1; i >= lo&&inorder[i] != root; i--);
		node->left = create(postorder, inorder, lo, i, mid - 1, begin - (hi - mid));
	}
	
	return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

	if (postorder.size() == 0 || inorder.size() == 0) return nullptr;

	int root = postorder[postorder.size()-1];
	int i = 0;
	for (i; i < inorder.size() && root != inorder[i]; i++);

	return create(postorder, inorder, 0, i, inorder.size() - 1, postorder.size() - 1);
}
void print(TreeNode*node)
{
	if (node == nullptr) return;
	print(node->left);
	cout << node->val << " ";
	print(node->right);
}

int main()
{
	vector<int> preorder = { 9,3,15,20,7 };
	vector<int> inorder = { 9,15,7,20,3 };

	TreeNode*root = buildTree(preorder, inorder);

	print(root);

	getchar();
	return 0;
}