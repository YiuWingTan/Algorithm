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
	//����min��max�ֲ������Ƿ�ֹ�����������ֵ��Сֵ��Ӱ�������������ֵ����Сֵ��Ѱ�ҡ�
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

	int min = 100000;//������ΪINT_MAX ��Ȼ�������ֵ���
	int max = 0;//������ΪINT_MIN ��Ȼ�������ֵ���

	getMax(root, min, max);

	return result;
}


int main()
{


	getchar();
	return 0;
}

