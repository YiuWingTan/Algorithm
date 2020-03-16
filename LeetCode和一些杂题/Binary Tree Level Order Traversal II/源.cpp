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


vector<vector<int>> levelOrderBottom(TreeNode* root) {

	if (root == nullptr) return{};

	vector<vector<int>> result;
	vector<TreeNode*> arr;
	TreeNode* node;
	arr.push_back(root);
	arr.push_back(nullptr);
	int count = 1;

	while (count != 0)
	{
		int index = arr.size() - count-1;
		count = 0;
		for (index; index < arr.size()-1; index++)
		{
			node = arr[index];
			if (node->right != nullptr) {
				arr.push_back(node->right);
				count++;
			}
			if (node->left != nullptr){
				arr.push_back(node->left);
				count++;
			}
			
		}
		arr.push_back(nullptr);
	}

	//Ìí¼Óµ½resultÖÐ
	int index = 0;
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		if (arr[i] == nullptr)
		{
			result.push_back({});
			index++;
			continue;
		}
		result[index].push_back(arr[i]->val);
	}
	return result;

}

int main()
{




	getchar();
	return 0;
}
