
#include<iostream>
#include<queue>
using namespace std;

int w, h;
int num = 1;
char mm[20][20];
int movex[] = {0,0,1,-1};
int movey[] = {1,-1,0,0};

void search(int orix,int oriy)
{
	queue<int> que;
	que.push(orix);
	que.push(oriy);
	mm[oriy][orix] = ' ';

	while (!que.empty())
	{
		int x = que.front(); que.pop();
		int y = que.front(); que.pop();

		for (int k = 0; k < 4; k++)
		{
			int mx = x + movex[k];
			int my = y + movey[k];

			if (mx < 0 || mx >= w) continue;
			if (my < 0 || my >= h) continue;
			if (mm[my][mx] == ' ' || mm[my][mx] == '#') continue;
			 
			que.push(mx);
			que.push(my);
			mm[my][mx] = ' ';
			num++;
		}
	}



}


int main()
{
	
	while (cin >> w >> h)
	{
		if (w == 0 && h == 0) break;
		int x, y;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{

				cin >> mm[i][j];

				if (mm[i][j] == '@')
				{
					x = j;
					y = i;
				}
			}
		}

		
		search(x,y);

		cout << num << endl;
		num = 1;

	}


	return 0;
}




