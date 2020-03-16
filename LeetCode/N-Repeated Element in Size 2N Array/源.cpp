/*
主题哈希表，难度简单
*/

#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int key;
	int value;
};

int repeatedNTimes(vector<int>& A) {

	vector<vector<Node>> list;
	list.resize(100);
	Node maxNode = {-1,0};

	for (int i = 0; i < A.size(); i++)
	{
		int key = A[i] % 100;
		int len = list[key].size();
		int j = 0;
		for (; j < len; j++)
		{
			if (list[key][j].key == A[i])
			{
				return A[i];
			}
		}
		if (j == len) list[key].push_back({A[i],1});
	}

	return maxNode.key;
}

int main()
{
	vector<int> list = { 2,1,2,5,3,2 };

	int num = repeatedNTimes(list);
	printf("最多重复次数的是  %d\n",num);

	getchar();
	return 0;
}


/* 优秀解决方案
int repeatedNTimes(vector<int>& A) {
unordered_set<int> unique;
for (int i = 0; i < A.size(); ++i) {
if (unique.find(A[i]) == unique.end())
unique.insert(A[i]);
else
return A[i];
}

}
*/