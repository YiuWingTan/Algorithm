#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int val = 0;

void distribute(TreeNode* node,TreeNode* par)
{
	if (node == nullptr) return;
	distribute(node->left,node);
	distribute(node->right,node);


	//如果当前的节点小于1 就从上面的顶点借一个
	//如果当前的节点大于1 就把值交给父节点

	if (node->val > 1){
		par->val += node->val - 1;
		val += node->val - 1;
	}else if (node->val < 1) {
		par->val -= (1-node->val);
		val += (1-node->val);
	}


}

int distributeCoins(TreeNode* root) {

	if (root == nullptr) return 0;
	val = 0;
	distribute(root,nullptr);

	return val;

}


int main()
{


	getchar();
	return 0;
}

