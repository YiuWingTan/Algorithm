#include<iostream>

using namespace std;


int a[1001];

int main()
{

	int n;

	while (cin >> n)
	{

		for (int i = 1; i <=n; i++)
			cin >> a[i];

		int count = 1;
		int target = -60;

		for (int i = 1; i <=n; i++)
		{
			if (a[i] != target) {
				count--;
			}
			else count++;
			
			if (count <= 0)
			{
				target = a[i];
				count = 1;
			}
		}

		if(count>1)
			cout << target << endl;
		else cout << "no"<<endl;
	}

	return 0;
}


