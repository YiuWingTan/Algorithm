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

vector<int> inorderTraversal(TreeNode* root) {

	if (root == nullptr) return{};

	stack<TreeNode*> st;
	vector<int> inorder;
	st.push(root);

	while (!st.empty())
	{
		auto node = st.top();

		if (node == nullptr) {
			st.pop();
			node = st.top(); st.pop();
			inorder.push_back(node->val);
			st.push(node->right);
		}
		st.push(node->left);
	}

	return inorder;
}

int main() {


	getchar();
	return 0;
}

