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


vector<vector<int>> levelOrder(TreeNode* root) {

	if (root == nullptr) return{};

	queue<TreeNode*> que;
	vector<vector<int>> result;
	vector<int> tmp;
	TreeNode* node;
	que.push(root);
	int count = 1;

	while (!que.empty())
	{
		node = que.front();
		tmp.push_back(node->val);
		que.pop();
		if(node->left!=nullptr)
			que.push(node->left);
		if (node->right != nullptr)
			que.push(node->right);
		if ((--count) == 0)
		{
			count = que.size();
			result.push_back(tmp);
			tmp.clear();
		}
	}

	return result;

}


int main()
{



	getchar();
	return 0;
}