#include<iostream>
using namespace std;



int main()
{
	int n,r;

	cin >> n;

	cin >> r;

	int *x = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	int k = 0;
	int mark = 0;
	int d = 0;
	while (true)
	{
		d = x[k]+r;
		int i = k;
		for (; i < n; i++)
		{
			if (x[i] > d) { k = i; mark++; break; }
		}
		if (i == n) break;
	}
	cout << "至少要进行"<<mark<<"次标记"<<endl;

	system("pause");
    return 0;
}

