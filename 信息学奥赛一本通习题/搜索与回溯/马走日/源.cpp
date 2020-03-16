#include<iostream>
#include<vector>
using namespace std;

int roadcount = 1;
int num;
int r, c;
int mm[11][11];

vector<int> nums;
int movei[] = {1,1,-1,-1,2,2,-2,-2};
int movej[] = {2,-2,2,-2,1,-1,1,-1};

void search(int _i,int _j)
{
	if (roadcount == r * c)
	{
		num++;
		return;
	}

	for (int k = 0; k < 8; k++)
	{
		int ti = _i + movei[k];
		int tj = _j + movej[k];

		if (ti < 0 || ti >= r) continue;
		if (tj < 0 || tj >= c) continue;
		if (mm[ti][tj]) continue;

		mm[ti][tj] = 1;
		roadcount++;

		search(ti,tj);

		mm[ti][tj] = 0;
		roadcount--;

	}

}


int main()
{
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int _i, _j;
		cin >> r >> c>>_i>>_j;
		roadcount = 1;
		num = 0;
		mm[_i][_j] = 1;
		search(_i,_j);
		mm[_i][_j] = 0;
		nums.push_back(num);
	}

	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i]<<endl;
	}


	return 0;
}


