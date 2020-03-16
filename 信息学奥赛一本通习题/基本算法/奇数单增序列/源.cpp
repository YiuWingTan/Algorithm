#include<iostream>
#include<vector>

using namespace std;

int a[500];
int b[500];

void change(int i,int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void quickSort(int lo,int hi)
{
	if (lo >= hi) return;
	int i = lo + 1;
	int k = lo;
	int j = hi;

	while (i <= j)
	{
		if (a[i] < a[k]) change(i++,k++);
		else if (a[i] > a[k]) change(i,j--);
		else i++;
	}

	quickSort(lo,k-1);
	quickSort(j+1,hi);

}


int main()
{
	int n;


	cin >> n;


	for (int i = 0; i < n; i++) cin>>b[i];

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i] & 1) a[j++] = b[i];
	}

	quickSort(0,j-1);

	for (int i = 0; i < j-1; i++)
	{
		cout << a[i] << ",";
	}
	cout << a[j-1]<<endl;

	
	return 0;
}



