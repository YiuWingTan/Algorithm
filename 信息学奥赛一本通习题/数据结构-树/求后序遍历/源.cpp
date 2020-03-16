

#include<iostream>
#include<string>
using namespace std;

void calBackOrder(string&pre,string&mid,int pi,int pj,int mi,int mj)
{
	if (pi > pj || mi > mj) return;

	int i = mi;

	while (mid[i] != pre[pi])i++;

	calBackOrder(pre,mid,pi+1,pi+(i - mi),mi,i-1);
	calBackOrder(pre,mid,pi+(i -mi+1),pj,i+1,mj);

	cout << mid[i];
}


int main()
{
	string pre, mid;
	cin >> pre >> mid;

	calBackOrder(pre,mid,0,pre.size()-1,0,mid.size()-1);
	cout << endl;

	return 0;
}


