#include<iostream>
#include<vector>
using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int result;

void getSum(TreeNode* node,int *tmp)
{
	if (node == nullptr) return;

	*tmp *= 10;
	*tmp += node->val;
	if (node->left == nullptr&&node->right == nullptr) result += *tmp;

	getSum(node->left, tmp);
	getSum(node->right, tmp);

	*tmp /= 10;
	*tmp += -node->val;
}


int sumNumbers(TreeNode* root) {

	if (root == nullptr) return 0;

	int tmp = 0;

	getSum(root,&tmp);

	return result;
}



int main()
{

	int sum = 1;
	sum += 2 * 5;
	cout << sum;
	getchar();
	return 0;
}
