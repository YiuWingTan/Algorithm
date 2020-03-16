#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

//递归解决方案
TreeNode* Create(vector<int>&nums,int lo,int hi)
{
	if (lo > hi) return nullptr;
	int mid = lo+(hi - lo) / 2;

	TreeNode* node = new TreeNode(nums[mid]);

	node->left = Create(nums,lo,mid-1);
	node->right = Create(nums,mid+1,hi);

	return node;
}

//特殊解决方案
TreeNode*Create(vector<int>&nums)
{
	if (nums.size() == 0) return nullptr;
	
	int i = 1;
	TreeNode*node = nullptr;
	TreeNode*root = new TreeNode(nums[0]);
	queue<TreeNode*> st;
	st.push(root);

	while (!st.empty())
	{
		node = st.front(); st.pop();
		if (i < nums.size())
		{
			node->left = new TreeNode(nums[i]);
			st.push(node->left);
		}
		if (i + 1 < nums.size())
		{
			node->right = new TreeNode(nums[i + 1]);
			st.push(node->right);
		}
		i += 2;
	}

	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {

	if (nums.size() == 0) return nullptr;

	//TreeNode*root = Create(nums,0,nums.size()-1);
	TreeNode*root = Create(nums);
	return root;
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
	vector<int> arr = { -10,-3,0,5,9 };

	auto root = sortedArrayToBST(arr);

	print(root);

	getchar();
	return 0;
}