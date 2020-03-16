#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int result = 0;
int Max(int x, int y, int z)
{
	return x > y ? x>z ? x : z : y>z ? y : z;
}
int Min(int x, int y, int z)
{
	return x < y ? x<z ? x : z : y<z ? y : z;
}


void getMax(TreeNode*node, int& _min, int& _max)
{
	if (node == nullptr) return;
	//创建min和max局部变量是防止左子树的最大值最小值会影响右子树的最大值和最小值的寻找。
	int max = _max = 0;
	int min = _min = 100000;
	getMax(node->left, min, max);
	getMax(node->right, _min, _max);
	_min = Min(_min, min, node->val);
	_max = Max(_max, max, node->val);
	result = Max(result, abs(node->val - _min), abs(node->val - _max));

}
int maxAncestorDiff(TreeNode* root) {

	if (root == nullptr) return 0;

	int min = 100000;//不能设为INT_MAX 不然会出现数值溢出
	int max = 0;//不能设为INT_MIN 不然会出现数值溢出

	getMax(root, min, max);

	return result;
}


int main()
{


	getchar();
	return 0;
}

