#include<iostream>
#include<vector>
#include<stack>


using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void get(TreeNode* root,vector<int>&result)
{
	if (root == nullptr) return;
	get(root->left,result);
	result.push_back(root->val);
	get(root->right,result);
}


//解法二,使用双栈
void get2(TreeNode* root, vector<int>&result)
{
	stack<TreeNode*> pre;
	stack<TreeNode*> back;
	TreeNode* mid;
	pre.push(root);

	while (!pre.empty()) {
		mid = pre.top();
		pre.pop();
		if (mid == nullptr)
		{
			if (!back.empty())
			{
				result.push_back(back.top()->val);
				back.pop();
			}
		}
		else if (mid->left == nullptr&&mid->right == nullptr)
		{
			result.push_back(mid->val);
			if (!back.empty())
			{
				result.push_back(back.top()->val);
				back.pop();
			}
		}
		else
		{
			pre.push(mid->right);
			pre.push(mid->left);
			back.push(mid);
		}
	}

	while (!back.empty())
	{
		result.push_back(back.top()->val);
		back.pop();
	}

}

//解法三 使用单栈
void get3(TreeNode*root,vector<int>&result)
{
	if (root == nullptr) return;
	stack<TreeNode*> st;
	TreeNode* mid = root->left;
	st.push(root);

	while (!st.empty())
	{
		while (mid != nullptr)
		{
			st.push(mid);
			mid = mid->left;
		}
		result.push_back(st.top()->val);
		st.pop();
		mid = mid->right;
	}

}

vector<int> inorderTraversal(TreeNode* root) {

	vector<int> result;

	if (root == nullptr) return result;

	//get(root,result);//-解法一
	
	get2(root,result);


	return result;


	
}



int main()
{

	getchar();
	return 0;
}