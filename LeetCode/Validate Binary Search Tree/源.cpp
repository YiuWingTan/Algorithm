#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int p = INT_MIN;
bool result = true;

//利用中序
void getMidOrder(TreeNode*node,vector<int>&arr)
{
	if (node == nullptr) return;
	getMidOrder(node->left,arr);
	arr.push_back(node->val);
	getMidOrder(node->right,arr);
}

//中序遍历优化版

bool getMidOrder(TreeNode*node)
{
	if (!result) return;
	if (node == nullptr) return;
	getMidOrder(node->left);
	if (p != INT_MIN)
	{
		result = p >= node->val ? false : true;
		p = node->val;
	}
	else p = node->val;
	getMidOrder(node->right);
	return;
}

bool isValidBST(TreeNode* root) {

	if (root == nullptr) return true;

	vector<int> arr;
	getMidOrder(root,arr);
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] >= arr[i + 1]) return false;
	}
	return true;
}

int main()
{


}
