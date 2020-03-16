#include<iostream>
#include<vector>
#include<string>
#include"DataStruct.h"
#include<stack>
#include<queue>

/*判断一颗树的子结构*/

bool judge(BinaryTreeNode<int>*node, BinaryTreeNode<int>*target)
{
	if (target == nullptr) return true;
	if (node == nullptr) return false;
	if (node->val == target->val)
	{
		if(judge(node->left,target->left)&& judge(node->right, target->right))
			return true;
	}
	return false;
}

bool isChildStruct(BinaryTreeNode<int>*node,BinaryTreeNode<int>*target)
{
	if (target == nullptr) return true;
	if (node == nullptr) return false;
	bool result = false;

	if (node->val == target->val) result |= judge(node,target);

	if(!result)
		result |= isChildStruct(node->left,target);
	if(!result)
		result |= isChildStruct(node->right,target);

	return result;
}
void IsChildStruct()
{
	vector<int> prev1 = {8,8,9,2,4,7,7};
	vector<int> mid1 =  {9,8,4,2,7,8,7};
	vector<int> prev2 = {8,9,3};
	vector<int> mid2 = {9,8,3};
	int k1 = 5;
	int k2 = 1;
	auto tree1 = CreateTreeByPreOrderAndMidOrder(prev1,mid1,k1);
	ShowTree(tree1);
	cout << endl<<endl;
	auto tree2 = CreateTreeByPreOrderAndMidOrder(prev2,mid2,k2);
	ShowTree(tree2);
	cout << endl << endl;
	bool result = isChildStruct(nullptr,tree2);
	printf("%s\n",result?"是子结构":"不是子结构");
	delete tree1;
	delete tree2;
}

/********************/

/*****************************************二叉树的镜像********************************************/
BinaryTreeNode<int>* mirrorTree(BinaryTreeNode<int>*tree)
{
	if (tree == nullptr) return nullptr;

	BinaryTreeNode<int>* left = tree->left;
	BinaryTreeNode<int>* right = tree->right;

	tree->left = mirrorTree(right);
	tree->right = mirrorTree(left);

	return tree;

}
//一个树的镜像
void MirrorTree()
{
	vector<int> prev = {1,2,3,4,5};
	vector<int> mid =  {5,4,3,2,1};
	int k = 4;

	auto tree = CreateTreeByPreOrderAndMidOrder(prev, mid, k);
	ShowTree(tree);
	tree = mirrorTree(tree);
	ShowTree(tree);
	delete tree;
}
/*************************************************************************************************/

/**************************************判断一颗树是否是对称的*************************************/

bool isSymmetrical(BinaryTreeNode<int> *node1,BinaryTreeNode<int> *node2)
{
	if (node1 == nullptr&&node2 == nullptr) return true;
	if (node1 == nullptr || node2 == nullptr) return false;

	if (node1->val != node2->val) return false;

	return isSymmetrical(node1->left,node2->right)&&isSymmetrical(node1->right,node2->left);
}
void IsSymmetrical()
{
	vector<int> prev = { 8,6,5,7,6,7,5 };
	vector<int> mid = { 5,6,7,8,7,6,5 };
	int k = 3;

	BinaryTreeNode<int> *tree = CreateTreeByPreOrderAndMidOrder(prev,mid,k);

	ShowTree(tree);

	bool isOk = isSymmetrical(tree->left,tree->right);

	printf("%s\n",isOk?"是一个对称树":"不是一个对称树");

	delete tree;
}

/*******************************************顺时针打印矩阵******************************************************/

void printfMatrix(vector<vector<int>> &matrix)
{
	if (matrix.size() == 0) return;
	int col = matrix[0].size();
	int row = matrix.size();
	int i, j;
	int starti,startj;
	int endi, endj;
	startj = starti = 0;
	endi = row - 1;
	endj = col - 1;

	while (starti <= endi&&startj <= endj)
	{
		for (i = starti, j = startj; j <= endj; j++) cout << matrix[i][j]<<" ";
		if (endi > starti)
		{
			for(j = endj,i = starti+1;i<=endi;i++) cout << matrix[i][j] << " ";
			for(j = endj-1,i = endi;j>=startj;j--) cout << matrix[i][j] << " ";
			if(startj!=endj)
				for(i = endi-1,j = startj;i>starti;i--) cout << matrix[i][j] << " ";
		}
		
		starti++;
		startj++;
		endi--;
		endj--;
	}
	
}

void PrintfMatrixClockWish()
{
	vector<vector<int>> matrix = {
		
	};
	printfMatrix(matrix);
}

/***************************************************************************************************/


/*包含min函数的栈*/

class MinStack
{
private:
	stack<int> m_data;
	stack<int> m_min;
public:
	MinStack()
	{
		printf("默认");
	}
	void push(int val)
	{
		m_data.push(val);
		if (m_min.empty()||val < m_min.top())
		{
			m_min.push(val);
		}
		else
		{
			m_data.push(val);
			m_min.push(m_min.top());
		}
	}
	int pop()
	{
		if (m_data.empty()) throw exception("栈为空");
		int val = m_data.top();
		m_data.pop();
		m_min.pop();
		return val;
	}
	int min()
	{
		if (m_min.empty()) throw exception("为空");
		return m_min.top();
	}
};

/*****************/

/*栈的压入弹出序列*/

bool pushAndPopOrder(string &s,string &p)
{
	if (s.size() != p.size()) return false;
	if (s.size() == 0) return true;
	stack<char> st;
	int i, j;
	i = j = 0;
	st.push(s[0]);
	
	while (i < s.size()&&!st.empty())
	{
		if (st.top() == p[j]) { st.pop(); j++; }
		else
		{
			if(i+1<s.size())
				st.push(s[i+1]);
			i++;
		}
	}
	return st.empty();
}


void PushAndPopOrder()
{
	string s = "1";
	string p = "4";
	printf("%s\n", pushAndPopOrder(s,p)?"合法序列":"非法序列");
}

/******************/

/*从上到下打印二叉树相关题目*/

//按层打印二叉树
void printfBrinaryTreeFromTopToDown1(BinaryTreeNode<int> *tree)
{
	if(tree == nullptr) return ;
	
	queue<BinaryTreeNode<int>*> que;
	que.push(tree);
	int n = 0;
	int i = 0;
	while (!que.empty())
	{
		n = que.size();
		for (i = 0; i < n; i++)
		{
			cout << que.front()->val << " ";
			if(que.front()->left!=nullptr)
				que.push(que.front()->left);
			if(que.front()->right!=nullptr)
				que.push(que.front()->right);
			que.pop();
		}
		cout << endl;
	}
}
//之字型打印二叉树
void printfBrinaryTreeFromTopToDown2(BinaryTreeNode<int> *tree)
{
	if (tree == nullptr) return;

	stack<BinaryTreeNode<int> *> q2;//保存倒序的点
	stack<BinaryTreeNode<int> *> q1;//保存顺序的点
	bool order = true;//表示是否是顺序
	q1.push(tree);

	while (!q1.empty() || !q2.empty())
	{
		if (order)
		{
			cout << q1.top()->val<<" ";
			if (q1.top()->left != nullptr) q2.push(q1.top()->left);
			if (q1.top()->right != nullptr) q2.push(q1.top()->right);
			q1.pop();
		}
		else
		{
			cout << q2.top()->val<<" ";
			if (q2.top()->right != nullptr) q1.push(q2.top()->right);
			if (q2.top()->left != nullptr) q1.push(q2.top()->left);
			q2.pop();
		}
		if (order&&q1.empty()) { order = false; cout << endl; }
		if (!order&&q2.empty()) { order = true; cout << endl; }
	}


}
void PrintfBrinaryTree()
{
	vector<int> prev = {1,2,4,8,9,10} /*{1,2,4,8,9,5,10,11,3,6,12,13,7,14,15}*/;
	vector<int> mid =  {10,9,8,4,2,1} /*{8,4,9,2,10,5,11,1,12,6,13,3,14,7,15}*/;
	int k = 5;
	BinaryTreeNode<int> *tree = CreateTreeByPreOrderAndMidOrder(prev,mid,k);

	printfBrinaryTreeFromTopToDown2(tree);

	deleteTree(tree);
}

/********************/

/*判断一个后序序列是否能称为一个二叉搜索树*/

bool judegBackOrder(int *arr,int lo,int hi)
{
	if (lo >= hi||arr == nullptr) return true;

	int left = lo;
	int right = hi - 1;
	for (left = right; arr[left] > arr[hi] && left >= lo; left--);
	for (int i = left; i >= lo; i--)
	{
		if (arr[i] > arr[hi]) return false;
	}
	return judegBackOrder(arr,lo,left)&& judegBackOrder(arr,left+1,right);
}

void JudgeBackOrder()
{
	int arr[] = {9,13,12,11,10,8};

	bool result = judegBackOrder(arr, 0, (sizeof(arr) / sizeof(int))-1);

	printf("%s\n",result?"符合":"不符合");
}

/******************************************/

/*二叉树中和为某一值的路径*/

void valuePath(BinaryTreeNode<int> *node,
	vector<vector<int>> &results,vector<int>&path,
	int val,int targetVal)
{
	if (node == nullptr) return;
	val += node->val;
	path.push_back(node->val);
	if (val == targetVal)
	{
		results.push_back(path);
	}
	valuePath(node->left, results, path, val, targetVal);
	valuePath(node->right, results, path, val, targetVal);
	path.pop_back();
	return;
}

void ValuePath()
{
	vector<int> prev = {8,6,4,2,0,5,1,10 } /*{1,2,4,8,9,5,10,11,3,6,12,13,7,14,15}*/;
	vector<int> mid = { 0,2,4,6,1,5,8,10} /*{8,4,9,2,10,5,11,1,12,6,13,3,14,7,15}*/;
	int k = 6;
	BinaryTreeNode<int> *tree = CreateTreeByPreOrderAndMidOrder(prev, mid, k);
	vector<vector<int>> result;
	vector<int> path;
	int target = 20;
	valuePath(tree,result,path,0,target);

	for(int i = 0;i<result.size();i++)
	{ 
		for (int j= 0; j < result[i].size(); j++)
		{
			cout << result[i][j]<<" ";
		}
		cout << endl;
	}

	deleteTree(tree);
}

/**************************/


/*将一个二叉搜索树转换成双向链表*/

//找一个最小值
BinaryTreeNode<int>* findSmall(BinaryTreeNode<int> *node)
{
	if (node == nullptr) return nullptr;
	BinaryTreeNode<int> *p = node;
	while (p->left != nullptr) p = p->left;
	return p;
}

BinaryTreeNode<int>* findBiggest(BinaryTreeNode<int> *node)
{
	if (node == nullptr) return nullptr;

	BinaryTreeNode<int> *p = node;
	while (p->right != nullptr)
	{
		p = p->right;
	}
	return p;
}

BinaryTreeNode<int>* translateTree(BinaryTreeNode<int> *node,bool isLeft)
{
	if (node == nullptr) return  nullptr;

	auto leftNode = translateTree(node->left,true);
	auto rightNode = translateTree(node->right,false);

	node->left = leftNode;
	if(leftNode!=nullptr)
		leftNode->right = node;
	node->right = rightNode;
	if(rightNode!=nullptr)
		rightNode->left = node;

	if (isLeft) return findBiggest(node);
	return findSmall(node);
}

//正常树形测试
void tttdlText1()
{
	vector<int> prev = { 10,6,4,8,14,12,16 } /*{1,2,4,8,9,5,10,11,3,6,12,13,7,14,15}*/;
	vector<int> mid = { 4,6,8,10,12,14,16 } /*{8,4,9,2,10,5,11,1,12,6,13,3,14,7,15}*/;
	int k = 3;
	BinaryTreeNode<int> *tree = CreateTreeByPreOrderAndMidOrder(prev, mid, k);
	BinaryTreeNode<int> *list = translateTree(tree, false);
	BinaryTreeNode<int> *front = list;
	BinaryTreeNode<int> *back = nullptr;
	printf("前序输出:\n");

	while (front != nullptr)
	{
		if (front->right == nullptr) back = front;
		cout << front->val << " ";
		front = front->right;
	}
	cout << endl;
	printf("后序输出:\n");

	while (back != nullptr)
	{
		cout << back->val << " ";
		back = back->left;
	}

	cout << endl << endl << endl;
	
}
//只有左子树
void tttdlText2()
{
	vector<int> prev = { 10,6,4,2,1 } /*{1,2,4,8,9,5,10,11,3,6,12,13,7,14,15}*/;
	vector<int> mid = {1,2,4,6,10} /*{8,4,9,2,10,5,11,1,12,6,13,3,14,7,15}*/;
	int k = 4;
	BinaryTreeNode<int> *tree = CreateTreeByPreOrderAndMidOrder(prev, mid, k);
	BinaryTreeNode<int> *list = translateTree(tree, false);
	BinaryTreeNode<int> *front = list;
	BinaryTreeNode<int> *back = nullptr;
	printf("前序输出:\n");

	while (front != nullptr)
	{
		if (front->right == nullptr) back = front;
		cout << front->val << " ";
		front = front->right;
	}
	cout << endl;
	printf("后序输出:\n");

	while (back != nullptr)
	{
		cout << back->val << " ";
		back = back->left;
	}

	cout << endl << endl << endl;
}
//只有右子树
void tttdlText3()
{
	vector<int> prev = { 10,11,12,13,14 } /*{1,2,4,8,9,5,10,11,3,6,12,13,7,14,15}*/;
	vector<int> mid = { 10,11,12,13,14 } /*{8,4,9,2,10,5,11,1,12,6,13,3,14,7,15}*/;
	int k = 0;
	BinaryTreeNode<int> *tree = CreateTreeByPreOrderAndMidOrder(prev, mid, k);
	BinaryTreeNode<int> *list = translateTree(tree, false);
	BinaryTreeNode<int> *front = list;
	BinaryTreeNode<int> *back = nullptr;
	printf("前序输出:\n");

	while (front != nullptr)
	{
		if (front->right == nullptr) back = front;
		cout << front->val << " ";
		front = front->right;
	}
	cout << endl;
	printf("后序输出:\n");

	while (back != nullptr)
	{
		cout << back->val << " ";
		back = back->left;
	}

	cout << endl << endl << endl;
}
//一个节点
void tttdlText4()
{
	vector<int> prev = { 10 } /*{1,2,4,8,9,5,10,11,3,6,12,13,7,14,15}*/;
	vector<int> mid = { 10 } /*{8,4,9,2,10,5,11,1,12,6,13,3,14,7,15}*/;
	int k = 0;
	BinaryTreeNode<int> *tree = CreateTreeByPreOrderAndMidOrder(prev, mid, k);
	BinaryTreeNode<int> *list = translateTree(tree, false);
	BinaryTreeNode<int> *front = list;
	BinaryTreeNode<int> *back = nullptr;
	printf("前序输出:\n");

	while (front != nullptr)
	{
		if (front->right == nullptr) back = front;
		cout << front->val << " ";
		front = front->right;
	}
	cout << endl;
	printf("后序输出:\n");

	while (back != nullptr)
	{
		cout << back->val << " ";
		back = back->left;
	}

	cout << endl << endl << endl;
}

void TranslateTreeToDoubleList()
{
	tttdlText1();
	tttdlText2();
	tttdlText3();
	tttdlText4();
}


/**************/

int main()
{
	TranslateTreeToDoubleList();
	getchar();
	return 0 ;
}