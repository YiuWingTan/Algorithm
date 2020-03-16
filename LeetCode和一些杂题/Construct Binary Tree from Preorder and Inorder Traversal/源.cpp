
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create(vector<int>&preorder,vector<int>&inorder,int lo,int mid,int hi,int begin)
{
	TreeNode* node = new TreeNode(inorder[mid]);
	int root;
	int i;
	if (mid > lo)
	{
		root = preorder[begin+1];
		for (i = mid - 1; i >= lo&&inorder[i] != root; i--);
		node->left = create(preorder,inorder,lo,i,mid-1,begin+1);
	}
	if (mid < hi)
	{
		root = preorder[begin+( mid-lo)+1];
		for (i = mid + 1; i <= hi&&root != inorder[i]; i++);
		node->right = create(preorder,inorder,mid+1,i,hi, begin + (mid - lo) + 1);
	}
	return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	if (preorder.size() == 0 || inorder.size() == 0) return nullptr;

	int root = preorder[0];
	int i = 0;
	for (i; i < inorder.size() && root != inorder[i]; i++);

	return create(preorder,inorder,0,i, inorder.size() - 1, 0);
}

void print(TreeNode*node)
{
	if (node == nullptr) return;
	print(node->left);
	cout << node->val<<" ";
	print(node->right);
}

int main()
{
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };

	TreeNode*root = buildTree(preorder,inorder);

	print(root);

	getchar();
	return 0;
}
