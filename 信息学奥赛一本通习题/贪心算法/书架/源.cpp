
#include<iostream>

using namespace std;


int height[20000];


void quickSort(int lo,int hi)
{
	if (lo >= hi) return;

	int i = lo+1, k = lo, j = hi;

	while (i <= j)
	{
		if (height[i] < height[k]) std::swap(height[i++],height[k++]);
		else if (height[i] > height[k]) std::swap(height[i],height[j--]);
		else i++;
	}

	quickSort(lo,k-1);
	quickSort(j+1,hi);

}


int main()
{

	int n, b;
	cin >> n >> b;

	for (int i = 0; i < n; i++) cin >> height[i];

	quickSort(0,n-1);
	
	int num = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (b <= 0) break;

		num++;
		b -= height[i];
	}

	cout << num << endl;

	return 0;
}



