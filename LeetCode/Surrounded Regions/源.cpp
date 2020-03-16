#include<iostream>
#include<vector>

/*
难度中等 主题 深度，宽度优先搜索，并查集
*/

using namespace std;

int row;
int col;

void check(vector<vector<char>>&board,int i,int j)
{
	board[i][j] = '1';

	if (i + 1 < row&&board[i + 1][j] == 'O') check(board, i + 1, j);
	if (i - 1 >= 0 && board[i - 1][j] == 'O') check(board,i-1,j);
	if (j + 1 < col&&board[i][j + 1] == 'O') check(board,i,j+1);
	if (j - 1 >= 0 && board[i][j - 1] == 'O') check(board,i,j-1);
}

void solve(vector<vector<char>>& board) {

	if (board.size() == 0) return;

	row = board.size();
	col = board[0].size();

	//检查四个边界，并把邻接的层变更成1
	
	for (int j = 0; j < board[0].size(); j++)
	{
		if (board[0][j] == 'O')
		{
			check(board,0,j);
		}
	}

	for (int j = 0; j < board[0].size(); j++)
	{
		if (board[board.size() - 1][j] == 'O')
		{
			check(board, board.size() - 1,j);
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][0] == 'O' )
			check(board, i,0);
	}

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][board[0].size() - 1]=='O')
		{
			check(board, i, board[0].size() - 1);
		}
	}


	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == '1') board[i][j] = 'O';
			else if (board[i][j] == 'O') board[i][j] = 'X';
		}
	}
}


int main() {


	getchar();
	return 0;

}



