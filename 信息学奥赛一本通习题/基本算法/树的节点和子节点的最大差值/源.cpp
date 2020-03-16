
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


int result = INT_MIN;

void getmax(TreeNode* root,int &_min,int &_max)
{
	if (root == nullptr) {


		_min = 0;
		_max = 0;
		return;
	}

	int lmin = 10000, lmax = 0;
	int rmin = 10000, rmax = 0;

	getmax(root->left,lmin,lmax);
	getmax(root->right,rmin,rmax);


	_min = min(lmin,rmin);
	_max = max(rmax,lmax);
	
	result = max(result,max(abs(root->val - _min),abs(root->val - _max)));
}

int maxAncestorDiff(TreeNode* root) {
	if (root == nullptr) return 0;
	int min, max;
	getmax(root,min,max);
	return result;
}