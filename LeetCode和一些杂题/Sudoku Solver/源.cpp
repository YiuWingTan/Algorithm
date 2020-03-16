/*
主题：哈希表，回溯 难度 困难
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Index
{
	int i;
	int j;
	Index(int _i,int _j)
	{
		i = _i;
		j = _j;
	}
};

vector<Index> indexs;
map<int, vector<int>> rows;
map<int, vector<int>> cols;
map<int, vector<int>> subs;

void show(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

bool isOk(int ri,int rj,int target)
{
	vector<int> &r = rows[target];
	vector<int> &c = cols[target];

	
	int key = (int)(ri / 3)*3 + (int)(rj / 3);

	for (int i = 0; i < r.size(); i++)
	{
		if (r[i] == ri)
			return false;
		if (c[i] == rj)
			return false;
	}

	for (int i = 0; i < subs[key].size(); i++)
	{
		if (target == subs[key][i])
			return false;
	}
	
	return true;
}


bool find(vector<vector<char>>& board,int n)
{
	if (n == indexs.size()) return true;
	int ri = indexs[n].i;
	int rj = indexs[n].j;
	int key = (int)(ri / 3)*3 + (int)(rj / 3);
	for (int i = 1; i < 10; i++)
	{
		if (isOk(ri,rj,i))
		{
			
			board[ri][rj] = (char)(i + '0');
			rows[i].push_back(ri);
			cols[i].push_back(rj);
			subs[key].push_back(i);
			if (find(board, n + 1)) return true;
			board[ri][rj] = '.';
			rows[i].pop_back();
			cols[i].pop_back();
			subs[key].pop_back();
		}
	}
	
	return false;
}

void solveSudoku(vector<vector<char>>& board) {

	int n = 0;

	for (int i = 0; i <9; i++)
	{
		for (int j = 0; j <9; j++)
		{
			if (board[i][j] != '.')
			{
				int num = (int)(board[i][j] - '0');
				rows[num].push_back(i);
				cols[num].push_back(j);
				subs[(int)(i / 3)*3 + j/3].push_back(num);
				n++;
			}
			else
			{
				indexs.push_back({i,j});
			}

		}
	}
	
	find(board, 0);
	subs.clear();
	indexs.clear();
	rows.clear();
	cols.clear();
}

int main()
{
	vector<vector<string>> ss =
	{
		{ "5","3",".",".","7",".",".",".","." },
		{ "6",".",".","1","9","5",".",".","." },
		{ ".","9","8",".",".",".",".","6","." },
		{ "8",".",".",".","6",".",".",".","3" },
		{ "4",".",".","8",".","3",".",".","1" },
		{ "7",".",".",".","2",".",".",".","6" },
		{ ".","6",".",".",".",".","2","8","." },
		{ ".",".",".","4","1","9",".",".","5" },
		{ ".",".",".",".","8",".",".","7","9" }
	};
	
	vector<vector<char>>board;
	board.resize(9);
	for (int i = 0; i < 9; i++)
	{
		
		for (int j = 0; j < 9; j++)
		{
			board[i].push_back(ss[i][j][0]);
		}
	}


	solveSudoku(board);

	show(board);

	getchar();
	return 0;
}