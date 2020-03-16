#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode* node)
{
	if (node == nullptr) return;

	print(node->left);
	cout << node->val;
	print(node->right);
}

TreeNode* clone(TreeNode*node)
{
	if (node == nullptr) return nullptr;

	TreeNode* newNode = new TreeNode(node->val);
	newNode->left = clone(node->left);
	newNode->right = clone(node->right);
	return newNode;
}

//动态规划
vector<TreeNode*> generateTrees(int n) {

	

	vector<TreeNode*> result = { nullptr };
	vector<TreeNode*> tmp;

	if (n == 0) return{};

	for (int i = 1; i <= n; i++)
	{

		for (int j = 0; j < result.size(); j++)
		{
			TreeNode newNode = TreeNode(i);
			TreeNode* oldTree = result[j];
			newNode.left = oldTree;
			TreeNode* tree = clone(&newNode);
			tmp.push_back(tree);

			if (oldTree != nullptr) {
				//一直往右子树前进
				TreeNode*rightNode = oldTree;
				TreeNode*drightNode = oldTree->right;
				while (drightNode != nullptr)
				{
					TreeNode newNode = TreeNode(i);
					rightNode->right = &newNode;
					newNode.left = drightNode;
					TreeNode* newTree = clone(oldTree);
					tmp.push_back(newTree);
					rightNode->right = drightNode;//恢复原状
					rightNode = drightNode;
					drightNode = drightNode->right;
				}
				rightNode->right = &newNode;
				newNode.left = nullptr;
				newNode.right = nullptr;
				tree = clone(oldTree);
				tmp.push_back(tree);
			}

		}
		result = tmp;
		tmp.clear();
	}

	return result;
}


int main()
{
	int n = 4;

	auto trees = generateTrees(n);

	for (int i = 0; i < trees.size(); i++)
	{
		print(trees[i]);
		cout << endl;
	}

	getchar();
	return 0;
}