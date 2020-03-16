/*
难度 中等，主题 ：哈希表
*/

#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

bool find(vector<int> &row,vector<int> &col,int ri,int rj,char target)
{ 
	int len = row.size();
	for (int i = 0; i < len; i++)
	{
		if (row[i] == ri || col[i] == rj)
		{
			printf("Y%c[%d,%d]/[%d,%d]\n", target,row[i],col[i],ri,rj);
			return true;
		}
		if (row[i] / 2 == ri / 2 && col[i] / 2 == rj / 2)
		{
			printf("N%c[%d,%d]/[%d,%d]\n", target,row[i], col[i], ri, rj);
			return true;
		}
	}
	row.push_back(ri);
	col.push_back(rj);
	return false;
}


bool isValidSudoku(vector<vector<char>>& board) {

	map<char, vector<int>> rowMap;
	map<char, vector<int>> colMap;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char target = board[i][j];
			if (board[i][j] != '.')
			{
				if (find(rowMap[target],colMap[target],i,j,target)) 
					return false;
			}
		}
	}
	return true;
}

int main()
{

	
	getchar();
	return 0;
}