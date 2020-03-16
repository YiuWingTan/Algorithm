#include<iostream>
#include<algorithm>
using namespace std;
struct stu
{
	int xh, ch, math, eng, sum;
};
bool cmp(stu x, stu y)
{
	if (x.sum>y.sum) return true;
	else if (x.sum == y.sum&&x.ch>y.ch) return true;
	else if (x.sum == y.sum&&x.ch == y.ch&&x.xh<y.xh) return true;
	else return false;
}
int main()
{
	int n;
	cin >> n;
	stu student[301];
	for (int i = 0; i<n; i++)
	{
		cin >> student[i].ch >> student[i].math >> student[i].eng;
		student[i].sum = student[i].ch + student[i].math + student[i].eng;
		student[i].xh = i + 1;
	}
	sort(student, student + n, cmp);
	for (int i = 0; i<5; i++)
	{
		cout << student[i].xh << " " << student[i].sum << endl;
	}
	return 0;
}