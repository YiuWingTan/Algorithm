
#include<iostream>

using namespace std;

struct Block
{
	int x, y;
};

Block arr[100000];

int cmp(int i,int j)
{
	if (arr[i].x != arr[j].x) return arr[i].x - arr[j].x;

	return arr[i].y - arr[j].y;
}

void quickSort(int lo,int hi)
{
	if (lo >= hi) return;

	int i = lo + 1;
	int k = lo;
	int j = hi;

	while (i <= j)
	{
		int key = cmp(i,k);
		if (key>0) swap(arr[i],arr[j--]);
		else if (key<0) swap(arr[i++],arr[k++]);
		else i++;

	}

	quickSort(lo,k-1);
	quickSort(j+1,hi);
}


int main()
{
	int n;
	int max = -10000;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x>>arr[i].y;
	}

	quickSort(0,n-1);
	max = arr[0].y;
	bool re = true;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].x > max) {
			re = false;
			break;
		}
		else if (arr[i].y > max) max = arr[i].y;
	}


	if (re)
	{
		cout << arr[0].x << " "<<max<<endl;
	}
	else
	{
		cout << "no"<<endl;
	}

	return 0;
}

