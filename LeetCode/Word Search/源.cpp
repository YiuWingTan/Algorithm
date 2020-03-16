#include<string>
#include<vector>
#include<iostream>

using namespace std;

int row;
int col;

bool find(vector<vector<char>> &board,string &word,int i,int j,int index)
{

	if (index == word.size()) return true;
	bool result = false;
	char mid = board[i][j];
	board[i][j] = '/';
	if (!result&&j - 1 >= 0 && board[i][j - 1] == word[index])
	{
		result |= find(board, word, i, j - 1, index + 1);	
	}
	if (!result&&j+ 1 <col && board[i][j + 1] == word[index])
	{
		result |= find(board, word, i, j + 1, index + 1);	
	}
	if (!result&&i - 1 >= 0 && board[i-1][j] == word[index])
	{
		result |= find(board, word,i-1,j, index + 1);
	}
	if (!result&&i + 1 <row && board[i+1][j] == word[index])
	{
		result |= find(board, word,i+1,j, index + 1);	
	}
	board[i][j] = mid;
	return result;
}


bool exist(vector<vector<char>>& board, string word) {
	
	row = board.size();
	if (row == 0) return false;
	col = board[0].size();
	if (col == 0) return false;

	bool result = false;
	char mid ;
	for (int i = 0; i < row && !result; i++)
	{
		for (int j = 0; j < col&&!result; j++)
		{
			if (board[i][j] == word[0])
			{
				result |= find(board, word, i, j, 1);
			}
		}
	}
	return result;
}


int main()
{
	vector<vector<char>> board
	{
		{'a','a'}
	};
	string word = "aaa";

	bool result = exist(board,word);

	if (result)
	{
		printf("´æÔÚ\n");
	}
	else
	{
		printf("²»´æÔÚ\n");
	}

	getchar();
	return 0;
}
