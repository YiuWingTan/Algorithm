

#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

char mm[101][101];

vector<string> re;

int movex[] = { 0,0,1,-1 };
int movey[] = {1,-1,0,0};

int orix, oriy;
int tarx, tary;
int n;

void search(int orix,int oriy,int tarx,int tary)
{

	queue<int> que;
	que.push(orix),que.push(oriy);
	mm[orix][oriy] = ' ';

	while (!que.empty())
	{
		int i = que.front(); que.pop();
		int j = que.front(); que.pop();

		if (i == tarx && j == tary) {
			re.push_back("YES\n");
			return;
		}
		
		for (int k = 0; k < 4; k++)
		{
			int x = j + movex[k];
			int y = i + movey[k];

			if (x < 0 || x >= n) continue;
			if (y < 0 || y >= n) continue;
			if (mm[y][x] == ' '|| mm[y][x] == '#') continue;
			que.push(y);
			que.push(x);
			mm[y][x] = ' ';
		}

	}
	re.push_back("NO\n");

}


int main()
{
	int k;
	cin >> k;

	for (int c = 0; c < k; c++)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				cin >> mm[i][j];
			}
		}
		cin >> orix >> oriy>>tarx>>tary;


		search(orix,oriy,tarx,tary);



	}


	for (int i = 0; i < k; i++)
	{
		cout << re[i];
	}


	return 0;
}
