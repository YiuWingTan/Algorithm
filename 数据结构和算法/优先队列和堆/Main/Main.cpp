// Main.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace std;

class MaxPQ
{
private:
	int*a;

	int size;

	int count;

	void extendPQ()
	{
		int*b = new int[size * 2];

		size *= 2;
		for (int i = 0; i < count; i++)
		{
			b[i] = a[i];
		}

		delete(a);

		a = b;
	}

	void swim(int k)
	{
		//int n = k;

		while (k/2 >= 1&&!less(k,k/2))
		{
			change(k,k/2);
			k /= 2;
		}
	}

	void sink(int k)
	{
		while (k * 2 <=count)
		{
			int  j = k * 2;

			if (j+1 <=count&&less(j, j + 1)) j++;
			if (!less(k, j)) break;
			change(k, j);
			k=j;

		}
	}

	bool less(int i, int j)
	{
		if (a[i] < a[j]) return true;
		return false;
	}


	void change(int i,int j)
	{
		int middle = a[i];

		a[i] = a[j];
		a[j] =middle;
	}

public:
	MaxPQ()
	{
		a = new int[50];
		size = 50;
		count = 0;
	}

	bool Insert(int n)
	{
		
		if (count >= size-1) extendPQ();
		count++;
		a[count] = n;

		swim(count);
		//cout << a[count]<<" ";
		return true;
	}

	int deleMax()
	{
		int max = a[1];

		a[1] = a[count];

		a[count] = -1;

		count--;

		sink(1);

		return max;
	}
};
inline void Output(int *a, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

//数值数组的方法
inline int* Copy(int a[], int length)
{
	int *b = new int[length];

	for (int i = 0; i < length; i++)
	{
		b[i] = a[i];
	}

	return b;
}


/*int main()
{
	int a[100], number = 0, mark = 0;

	while (mark >= 0)
	{
		cin >> mark;

		if (mark < 0) break;

		a[number++] = mark;
	}

	
	int* b = Copy(a, number);
	MaxPQ pq;
	for (int i = 0; i < number; i++)
	{
		pq.Insert(b[i]);
	}
	
	for (int i = 0; i < number; i++)
	{
		cout << pq.deleMax()<<" ";
	}

	delete(b);

	getchar();
	getchar();

    return 0;
}*/

