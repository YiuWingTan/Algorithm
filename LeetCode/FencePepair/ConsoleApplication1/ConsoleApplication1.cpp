#include<stack>
#include<iostream>
using namespace std;
#define MAXLINE 1024

inline void change(int *a,int i,int j)
{
	int middle = a[i];
	a[i] = a[j];
	a[j] = middle;
	//cout << "交换了"<<i<<"和"<<j<<endl;
}

inline void quickSort3(int *a,int lo,int hi)
{
	if (lo >= hi) return;

	int k = lo;
	int min = lo + 1;
	int max = hi;
	int v = a[lo];

	while (min<=max)
	{
		if (v < a[min]) { change(a, min, max--); }
		else if (v > a[min]) { change(a,min++,k++); }
		else { min++; }
	}
	
	quickSort3(a,lo,k);
	quickSort3(a,min,hi);

}

int main()
{
	stack<int> tree;
	int length;

	int n;

	cin >> length;

	cin >> n;

	int *l = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}

	quickSort3(l,0,n-1);
	/*for (int i = 0; i < n; i++)
	{
		cout << l[i]<<" ";
	}
	cout << endl;*/

	int k = 0;
	int min = l[0], pmin = 1;
	int count = 0;
	int cost = 0;
	
	while (pmin < n)
	{

		if (pmin == 1)  {
			tree.push(l[pmin]);
			tree.push(min);

		}
		else
		{
			tree.push(min);
			tree.push(l[pmin]);
			
			cost += min;
		}
		min = min + l[pmin];
		//cout << min << endl;
		pmin++;
		

	}
	tree.push(length);
	cost += length;
	cout << "花费是 "<<cost<<endl;


	system("pause");
	getchar();
}

