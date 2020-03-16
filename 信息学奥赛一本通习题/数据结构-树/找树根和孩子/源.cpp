

#include<iostream>
using namespace std;

struct Node
{
	Node()
	{
		parent = NULL;
		bor = NULL;
		child = NULL;
	}

	int val;
	int childCount = 0;
	Node* parent;
	Node* bor;
	Node* child;
};

Node nodes[201];


int main()
{
	int n,k;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int parent, child;
		cin >> parent >> child;

		
		nodes[child].bor =  nodes[parent].child;
		nodes[parent].child = &nodes[child];
		nodes[child].parent = &nodes[parent];
		nodes[parent].childCount++;
	}
	
	int maxChild = 0;
	int maxChildNode = 0;
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i].parent == NULL)
		{
			cout << i << endl;
		}

		if (maxChild < nodes[i].childCount)
		{
			maxChild = nodes[i].childCount;
			maxChildNode = i;
		}

	}

	//寻找最大的节点
	cout << maxChildNode << endl;


	for (int i = 1; i <= n; i++)
	{
		if (i != maxChildNode && nodes[i].parent == &nodes[maxChildNode])
			cout << i << " ";
	}
	cout << endl;

	return 0;
}




