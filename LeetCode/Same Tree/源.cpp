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


bool isSameTree(TreeNode* p, TreeNode* q) {

	queue<TreeNode*> que;
	que.push(p);
	que.push(q);

	TreeNode* n1;
	TreeNode*n2;

	while (!que.empty())
	{
		n1 = que.front(); que.pop();
		n2 = que.front(); que.pop();

		if (n1 == nullptr&&n2 == nullptr)
		{
			continue;
		}if (n1 != nullptr&&n2 != nullptr)
		{
			if (n1->val != n2->val) return false;
			que.push(n1->left);
			que.push(n2->left);
			que.push(n1->right);
			que.push(n2->right);
		}
		else return false;

	}
	return true;
}


int main()
{


	getchar();
	return 0;
}