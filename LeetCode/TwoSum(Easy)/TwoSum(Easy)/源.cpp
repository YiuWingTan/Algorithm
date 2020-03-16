#include<iostream>
#include<vector>
using namespace std;

struct Node
{

	int value;
	int index;

} ;

void change(vector<Node*> &nums,int i,int j)
{
	Node* c = nums[i];
	nums[i] = nums[j];
	nums[j]= c;
}

///三向切分快速排序
void Sort(vector<Node*>& nums,int lo,int hi)
{
	if (lo >= hi) return;
	int i = lo + 1;
	int v = nums[lo]->value;
	int gt = hi;
	int lt = lo;

	while (i <= gt)
	{
		if (v < nums[i]->value)change(nums,i,gt--);
		else if (v > nums[i]->value) change(nums,lt++,i++);
		else i++;
	}
	Sort(nums, lo, lt-1);
	Sort(nums,gt+1,hi);
}

vector<int> twoSum(vector<int>& nums, int target) {

	int i, j;

	vector<int> indices;
	vector<Node*>nodes;
	for (int k = 0; k < nums.size(); k++)
	{
		nodes.push_back(new Node{ nums[k],k });
	}

	Sort(nodes, 0, nums.size() - 1);

	for (Node* v : nodes)
	{
		cout << v->value << " ";
	}
	cout << endl;

	for (i =0; i<nums.size(); i++)
	{
		for (j = i+1; j<nums.size(); j++)
		{
			if ((nodes[i]->value + nodes[j]->value) == target)
			{
				indices.push_back(nodes[j]->index);
				indices.push_back(nodes[i]->index);
				return indices;
			}
		}

	}
	return indices;
}
int main()
{
	vector<int> nums{ -1,-2,-3,-4,-5};

	vector<int> result = twoSum(nums,-8);

	
	cout << "{";
	for (int i : result)
	{
		cout<<i<<" ";
	}
	cout << "}\n";

	getchar();

}