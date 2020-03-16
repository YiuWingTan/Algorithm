#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


void flatten(TreeNode* root) {

	if (root == nullptr) return;

	TreeNode* tail = root;
	TreeNode* target = root;
	vector<int> tmp;
	tmp.push_back(tail->val);
	while (true)
	{
		//Ñ°ÕÒÓÒÎ²½Úµã¡£
		while (tail->right != nullptr) { tail = tail->right; tmp.push_back(tail->val); }
		while (target!=nullptr&&target->left == nullptr) target = target->right;

		if (target == nullptr) return;
		tail->right = target->left;
		target->left = nullptr;
	}

	int i = 0;
	sort(tmp.begin(),tmp.end());
	while (root != nullptr)
	{
		root->val = tmp[i++];
		root = root->right;

	}

}


int main()
{


	getchar();
	return 0;
}