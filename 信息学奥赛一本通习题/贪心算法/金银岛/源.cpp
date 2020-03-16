

#include<iostream>
#include<cstdio>
using namespace std;

float re[10000];
int weight[100];
int value[100];
double v_w[100];
double keplision = 1e-8;

 void change(int i,int j)
{
	std::swap(weight[i],weight[j]);
	std::swap(value[i],value[j]);
	std::swap(v_w[i],v_w[j]);
}

 double cmpfunc(int i,int j)
{
	return v_w[i] - v_w[j];
}

void quickSort(int lo,int hi)
{
	if (lo >= hi) return;

	int i = lo + 1, k = lo, j = hi;

	while (i <= j)
	{
		float cmp = cmpfunc(i,k);

		if (cmp < -keplision)
			change(i, j--);
		else if (cmp > keplision)
			change(i++,k++);
		else i++;
		
	}

	quickSort(lo,k-1);
	quickSort(j+1,hi);

}


int main()
{
	int k;
	cin >> k;


	for (int n = 0; n < k; n++)
	{
		int w; cin >> w;
		int s; cin >> s;

		memset(weight,0,sizeof(weight));
		memset(value,0,sizeof(value));
		memset(v_w,0.0f,sizeof(v_w));

		for (int i = 0; i < s; i++)
		{
			cin >> weight[i] >> value[i];
			v_w[i] = value[i] / (double)weight[i];
		}

		quickSort(0,s-1);

		int i = 0;
		float v = 0;
		while (i<s&&w - weight[i] >= 0) {
			w -= weight[i];
			v += value[i];
			i++;
		}

		if (i < s)
		{
			v += w * v_w[i];
		}

		re[n] = v;

	}


	for (int i = 0; i < k; i++)
		printf("%.2f\n",re[i]);


	return 0;
}


