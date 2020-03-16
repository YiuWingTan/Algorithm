#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


TreeNode* construct(vector<int>&nums,int lo,int hi)
{
	if (lo > hi) return nullptr;
	if (lo == hi) return new TreeNode(nums[lo]);
	int max = lo;
	for (int i = lo; i <= hi; i++)
		if (nums[max] < nums[i]) max = i;

	TreeNode *node = new TreeNode(nums[max]);

	node->left = construct(nums,lo,max-1);
	node->right = construct(nums,max+1,hi);

	return node;

}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

	if (nums.size() == 0) return nullptr;

	return construct(nums,0,nums.size()-1);
}

int main()
{


	getchar();
	return 0;
}