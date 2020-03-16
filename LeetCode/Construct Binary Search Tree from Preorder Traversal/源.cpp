#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* construct(vector<int>& order,int lo,int hi)
{
	if (lo > hi) return nullptr;
	if (lo == hi) return new TreeNode(order[lo]);

	TreeNode* node = new TreeNode(lo);
	int i = lo+1;
	while (i <= hi&&order[i] <= order[lo])i++;
	node->left = construct(order,lo+1,i-1);
	node->right = construct(order,i,hi);
	return node;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
	
	if (preorder.size() == 0) return nullptr;

	TreeNode* root = construct(preorder,0,preorder.size()-1);

	return root;
}

int main()
{


	getchar();
	return 0;
}