#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*
´ò¼Ò½ÙÉá¶þ
*/

int max3(int a,int b,int c)
{
	return max(max(a,b),c);
}

int rob(vector<int> nums) {

	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return  max(nums[0], nums[1]);
	vector<int> dp1(nums.size(),0);
	vector<int> dp2(nums.size(), 0);
	int len = nums.size();
	dp2[0] = INT_MIN; dp2[1] = nums[1];
	dp1[0] = nums[0]; dp1[1] = max(dp1[0],nums[1]);

	for (int i = 2; i < len-1; i++)
	{

		dp2[i] = max3(dp2[i-1],nums[i]+dp2[i-2],nums[i]);
		dp1[i] = max(dp1[i - 1], nums[i] + dp1[i - 2]);
	}
	dp2[len - 1] = max(dp2[len-2],dp2[len-3]+nums[len-1]);
	return dp2[len - 1] > dp1[len - 2] ? dp2[len - 1] : dp1[len-2];

}


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int rob(TreeNode* node, int &child,int &childchild)
{
	if (node == nullptr)return 0;

	int l1 = 0, l2 = 0, r1 = 0, r2 = 0;

	rob(node,l1,l2);
	rob(node,r1,r2);

	child = node->val + l2+r2;
	childchild = max(l1, l2) + max(r1,r2);
	;
}

int rob(TreeNode* root) {
	
	if (root == nullptr) return 0;

	bool used;
	int child = 0, childchild = 0;
	 rob(root,child,childchild);
	 return max(child,childchild);
}


int main()
{
	cout<<rob({1, 2, 3, 4, 5, 1, 2, 3, 4, 5})<<endl;

	getchar();
	return 0;
}



