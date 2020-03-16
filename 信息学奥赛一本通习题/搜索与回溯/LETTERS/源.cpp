
#include<iostream>

using namespace std;

char mm[21][21];
 
int letter[26] = {0};
int s, r;
int mmax,num = 1;

int movex[] = {0,0,1,-1};
int movey[] = {1,-1,0,0};


void search(int m,int n)
{
	
	for (int k = 0; k < 4; k++)
	{
		int i = m + movey[k];
		int j = n + movex[k];
		char tmp;
		if (i < 0 || i >= r) continue;
		if (j < 0 || j >= s) continue;
		if (mm[i][j] == '.') continue;
		if (letter[mm[i][j] - 'A']>0) continue;

		tmp = mm[i][j];
		int index =  mm[i][j] - 'A';
		mm[i][j] = '.';
		letter[index] = 1;
		if (++num > mmax) mmax = num;

		search(i,j);


		mm[i][j] = tmp;
		letter[index] = 0;
		--num;
	}
}


int main()
{

	
	cin >> r >> s;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{

			cin >> mm[i][j];
		}
	}

	letter[mm[0][0] - 'A'] = 1;
	mm[0][0] = '.';
	search(0,0);

	cout << mmax << endl;

	return 0;
}
