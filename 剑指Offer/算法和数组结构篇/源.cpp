#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"DataStruct.h"
#include<stack>
#include<queue>
using namespace std;

//�ҳ������е��ظ�Ԫ�� ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
void duplicate()
{
	vector<int> arr{};
	vector<int> result;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]<0 || arr[i]>arr.size() - 1) return ;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		while (arr[i]>=0)
		{
			if (arr[arr[i]]<0)
			{
				arr[arr[i]] -= 1;
				if(arr[arr[i]] == -2)
					result.push_back(arr[i]);
				
				break;
			}
			else
			{
				int j = arr[i];
				int temp = arr[arr[i]];
				arr[i] = temp;
				arr[j] = -1;
			}
			
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<" ";
	}
	cout << endl;
}

int getCount(vector<int>&arr,int start,int end)
{
	int num = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] >= start&&arr[i]<=end) num++;
	}
	return num;
}

//���ı�ԭ���������ҳ������е��ظ�Ԫ�� ʱ�临�Ӷ� O(nlgn) �ռ临�Ӷ� O(1)
void duplicateNoChange()
{
	vector<int> arr = {};
	vector<int> result;
	
	int start = 1;
	int end = arr.size()-1;
	int mid;

	while (start < end)
	{
		mid = (end - start)/2+ start;

		if (getCount(arr, start, mid) > (mid - start + 1))
		{
			end = mid;
		}
		else 
		{
			start = mid+1;
		}
		
	}


	result.push_back(start);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<"  ";
	}
	cout << endl;
}

//��һ����ά�����в���ĳ��ֵ
bool findNumsFrom2Array()
{
	vector<vector<int>> arr
	{
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,12},
		{6,8,11,15}
	};
	int target = 14;
	int i = 0;
	int j = arr[0].size() - 1;

	while (i <arr.size() && j >= 0)
	{
		if (arr[i][j] < target) { i++; }
		else if (arr[i][j] > target) { j--; }
		else return true;
	}

	return false;
}

//��%20�滻���ַ����Ŀո���
void inserSpaceIntoString()
{
	string s = "hellow";
	vector<char> arr;
	arr.resize(1024);//�Ƚ�arr��С����Ϊ1024��
	int len = s.size();
	
	for (int i = 0; i < len; i++)
		arr[i] = s[i];

	int i,j;
	int size;
	i = j = len;
	for (int i = 0; i < len; i++)
		if (arr[i] == ' ') j += 2;
	size = j;
	if(j>i)
	for (i--,j--; i >= 0; i--,j--)
	{
		if (arr[i] == ' ')
		{
			arr[j--] = '0';
			arr[j--] = '2';
			arr[j] = '%';
		}
		else
		{
			arr[j] = arr[i];
		}
	}
	else printf("�ַ�����û�пո�\n");
	printf("ת������ַ�����\n");
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

//�鲢�����Ѿ������˵�����
void MergeTwoSortedArray() {

	int i,j,size;
	vector<int> arr1 = {5,63,6,9,7,4,12,65,45,15,4,1};
	vector<int> arr2 = {6,6,9,8,5,12,3,2,2118,8,7,4};
	i = arr1.size()-1;
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	arr1.resize(1024);
	size = i+arr2.size();
	j = arr2.size()-1;
	for (int k = size; k >= 0; k--)
	{
		if (i < 0)
		{
			arr1[k] = arr2[j--];
		}
		else if (j < 0)
		{
			arr1[k] = arr1[i--];
		}else if (arr1[i] > arr2[j])
		{
			arr1[k] = arr1[i--];
		}
		else
		{
			arr1[k] = arr2[j--];
		}
	}
	
	for (int i = 0; i <= size; i++)
	{
		cout << arr1[i]<<" ";
	}
	
	
}

//�ݹ�汾ʵ�ַ���
void ReverListRecursion(SingleListNode<int> *node)
{
	if (node == NULL) return;
	ReverListRecursion(node->next);
	cout << node->val << " ";
}
//��ת���һ������
void ReverList()
{
	vector<int> arr = {1,2,3,6,5,4,8,9,5};
	SingleListNode<int> *list = NULL;
	CreateSingleList(arr,list);
	ShowList(list);

	printf("\n��ת�������\n");
	stack<SingleListNode<int>*> st;

	SingleListNode<int> *node = NULL;
	while (node != NULL)
	{
		st.push(node);
		node = node->next;
	}

	while (!st.empty())
	{
		cout << st.top()->val<<" ";
		st.pop();
	}

	printf("\n�ݹ�汾ʵ��\n");
	ReverListRecursion(NULL);
	DeleteSingleList(list);
}

/*����ǰ��������������������һ����*/
vector<int> preOrder = {1,2,4,7,3,5,6,9};//ǰ��
vector<int> midOrder = {4,7,2,1,5,3,8,6};//����
BinaryTreeNode<int>* root;
BinaryTreeNode<int>* createTree(int par,int left,int right,int index)
{
	BinaryTreeNode<int> *node = new BinaryTreeNode<int>(midOrder[par]);

	
	//�ж���û��������
	if (par != left)
	{
		//��
		int leftIndex = index + 1;
		int i = left;
		for (; i < par&&midOrder[i]!=preOrder[leftIndex]; i++);
		if (i == par) 
			throw exception("�Ƿ�����");
		node->left = createTree(i,left,par-1,leftIndex);
	}
	//�ж���û��������
	if (par != right)
	{
		int rightIndex;
		if(par!=left)
			rightIndex = index + (par - left+ 1);
		else rightIndex = index + 1;
		int i = par+1;
		for (; i <= right&&preOrder[rightIndex] != midOrder[i]; i++);
		if(i>right) 
			throw exception("�Ƿ�����");
		node->right = createTree(i,par+1,right,rightIndex);
	}
	return node;
}
void CreateTreeByPreOrderAndMidOrder()
{
	if (preOrder.size() != midOrder.size()) return;

	int target = preOrder[0];
	int i = 0;
	for (; i < midOrder.size() && midOrder[i] != target; i++);
	root = createTree(i,0,midOrder.size()-1,0);
	ShowTree(root);
	root =  deleteTree(root);
}
/**********************************************/

/*�ҵ������������һ���ڵ�*/

void FindNextNodeInMidOrder()
{
	BinaryTreeNode<int>* tree = NULL;

	if (tree == NULL) return;

	if (tree->right != NULL)
	{
		//��һ�����
		BinaryTreeNode<int>* node = tree->right->left;
		while (node->left != NULL)
		{
			node = node->left;
		}
		cout << node->val;
	}
	else if (tree->par != NULL&&tree->par->left == tree)
	{
		//�ڶ������
		cout << tree->par->val;
	}
	else if (tree->par != NULL)
	{
		//���������
		BinaryTreeNode<int>* node = tree->par;
		while (node->par != NULL&&node->par->left != node)
		{
			node = node->par;
		}
		if (node->par != NULL) cout << node->val;
	}
}

/************����ջʵ��һ������**************/
stack<int> q1;
stack<int> q2;
int len = 0;
void push(int val)
{
	q1.push(val);
	len++;
}
int pop()
{
	if (len == 0) throw exception("Խ��");
	if (q2.empty())
	{
		while (!q1.empty())
		{
			q2.push(q1.top());
			q1.pop();
		}
	}
	int val = q2.top();
	q2.pop();
	len--;
	return val;
}

void ImplementQueueByTwoStack()
{
	vector<int> arr = {1,2,3,4,5,6,7,8,9};
	for (int i = 0; i < arr.size(); i++)
	{
		push(arr[i]);
	}
	while (len != 0)
	{
		cout << pop()<<" ";
	}
}

/**************************/

int main()
{
	ImplementQueueByTwoStack();

	getchar();
	return 0;
}