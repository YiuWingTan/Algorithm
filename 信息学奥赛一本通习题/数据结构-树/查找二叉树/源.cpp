#include<iostream>
using namespace std;

struct Node
{
	Node() { val = parent = left = right = 0; }
	int parent,left,right,val;
};

Node nodes[101];
int num;
bool isFind = false;

void find(int node, int target)
{
	if (node <= 0) return;

	if(!isFind)
		find(nodes[node].left,target);

	if(!isFind)
		num++;
	if (nodes[node].val == target)
		isFind = true;
	

	if (!isFind) find(nodes[node].right,target);

}

int main()
{

	int n,target;
	cin >> n >> target;

	int val, left, right,i = 1;
	
	for (; i <= n; i++)
	{
		cin >> val >> left >> right;
		nodes[i].val = val;
		nodes[i].left = left;
		nodes[i].right = right;

		nodes[left].parent = i;
		nodes[right].parent = i;
	}

	for (i = 1; i <= n; i++)
		if (nodes[i].parent == 0) break;

	find(i,target);

	cout << num << endl;

	return 0;
}


