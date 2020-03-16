
#include<iostream>

using namespace std;


int f(int n,int m)
{
	if (n < m) swap(n,m);

	if (n%m == 0) return m;

	return f(m,n-m);

}

int main()
{

	int n, m;

	cin >> n >> m;

	cout << f(n,m)<<endl;


	return 0;
}

