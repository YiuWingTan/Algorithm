#pragma once

#ifndef _UNION_H_
#define _UNION_H_

#include<vector>


//并查集的实现

class Union
{
public:
	Union(int n);
	virtual ~Union();
	void unite(int a,int b);
	int find(int n);
	bool same(int u,int v);
private:
	std::vector<int> par;//表示父节点
	std::vector<int> rank;//节点的高度
};
#endif // !_UNION_H_