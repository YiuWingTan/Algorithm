#include<iostream>
#include<vector>

using namespace std;



int climbStairs(int n) {
	
	if (n == 1) return 1;
	if (n == 2) return 2;

	int t_1 = 2;
	int t_2 = 1;
	int t = 0;

	for (int i = 3; i <= n; i++)
	{
		t = t_1 + t_2;
		t_2 = t_1;
		t_1 = t;
	}

	return t;
}


int main()
{
	int n = 2;

	cout << "有"<< climbStairs(n)<<"种方法爬到"<<n<<"阶楼梯"<<endl;

	getchar();
}