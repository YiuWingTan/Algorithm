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

vector<int> largestValues(TreeNode* root) {

	if (root == nullptr) return{};
	vector<int> result;
	int count = 1;
	int max = INT_MIN;
	queue<TreeNode*> que; que.push(root);

	while (!que.empty())
	{
		auto node = que.front();
		que.pop();

		if (node->val > max) max = node->val;
		if (node->left != nullptr) que.push(node->left);
		if (node->right != nullptr) que.push(node->right);

		if (--count == 0) {
			count = que.size();
			result.push_back(max);
			max = INT_MIN;
		}
	}
	return result;
}


int main()
{
	double arr[5] = { 0 };
	double* p = arr;

	for (int i = 0; i < 5; i++) cout << arr+i<<" ";

	cout << endl;

	cout << endl << p <<" "<< p + 1;
	cout << endl << endl;
	//cout << sizeof(double*);

	signed int a = 0xe0000000;
	unsigned int b = a;
	cout << (a == b);

	getchar();
	return 0;
}
