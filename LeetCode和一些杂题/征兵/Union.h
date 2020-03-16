#pragma once

#ifndef _UNION_H_
#define _UNION_H_

#include<vector>


//���鼯��ʵ��

class Union
{
public:
	Union(int n);
	virtual ~Union();
	void unite(int a,int b);
	int find(int n);
	bool same(int u,int v);
private:
	std::vector<int> par;//��ʾ���ڵ�
	std::vector<int> rank;//�ڵ�ĸ߶�
};
#endif // !_UNION_H_