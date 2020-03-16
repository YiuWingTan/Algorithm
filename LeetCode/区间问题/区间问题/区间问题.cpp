#include<iostream>
#include<string>
using namespace std;
inline void change(int *a,int i,int j)
{
	int middle = a[i];
	a[i] = a[j];
	a[j] = middle;
}
void quickSort3(int *,int ,int);

int main()
{
	int n;
	cin >> n;
	int *start = new int [n];
	int *end = new int[n];
	cout << "请输入开始时间"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> start[i];
	}
	cout << "请输入结束时间"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> end[i];
	}

	quickSort3(start,0,n-1);
	quickSort3(end,0,n-1);

	/*for (int i = 0; i < n; i++)
	{
		cout << start[i]<<"  ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << end[i] << "  ";
	}
	cout << endl;*/
	string str = "";
	int s = 0;
	int e = 0;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (start[i] > e)
		{
			str += (i+49)+" ";
			s = start[i];
			e = end[i];
			num++;
		}
	}

	cout << "结果为:"<<num<<" "<<str<<endl;

	system("pause");

    return 0;
}


void quickSort3(int *a ,int lo,int hi)
{
	if (lo >= hi) return;

	int k = lo;

	int min = lo+1;

	int max = hi;

	int v = a[lo];

	while (min <= max)
	{
		if (a[min] > v) { change(a, min, max--); }
		else if (a[min] < v) { change(a, min++, k++); }
		else { min++; }
	}

	quickSort3(a,lo,k);
	quickSort3(a,min,hi);
}

