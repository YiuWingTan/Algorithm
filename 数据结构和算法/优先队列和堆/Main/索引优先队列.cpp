#include<iostream>
using namespace std;


class IndexMaxPQ
{
private :
	int*pq;
	int *qp;
	int *elements;
	int N;
	int size;

	void extendPQ()
	{
		int*b = new int[N*2];

		int n = 1;

		while (n <= N)
		{
			b[n] = pq[n];
			n++;
			b[n] = pq[n];
			n *= 2;
		}


		delete(pq);

		pq = b;
	}

	void extendQP()
	{
		int*b = new int[size * 2];

		size *= 2;
		for (int i = 0; i < N; i++)
		{
			b[i] = qp[i];
		}

		delete(qp);

		qp = b;
	}

	void extendElements()
	{
		int*b = new int[size * 2];

		size *= 2;
		for (int i = 0; i < N; i++)
		{
			b[i] = elements[i];
		}

		delete(elements);

		elements = b;
	}

	void sink(int k)
	{
		while (k*2<=N)
		{
			int j = k*2;
			if (j + 1 <= N && less(j, j+1)) j++;
			if (less(j, k)) break;
			change(j,k);
			k = j;
		}
	}

	void swim(int k)
	{
		int n = k;

		while (k > 1 && !less(k, k / 2))
		{
			change(k,k/2);
			k /= 2;
		}
	}

	bool less(int i,int j)
	{
		if (elements[pq[i]] < elements[pq[j]]) return true;
		return false;
	}

	void  change(int i,int j)
	{
		int middle = pq[i];
		pq[i] = pq[j];
		pq[j] = middle;

		qp[pq[i]] = i;
		qp[pq[j]] = j;
	}

public:
	IndexMaxPQ()
	{
		size = 50;
		pq = new int[size];
		qp = new int[size];
		elements = new int[size];
		N = 0;
	}

	void Insert(int n)
	{
		if (++N >= size) { extendElements(); extendPQ(); extendQP(); }
		elements[N] = n;
		pq[N] = N;
		qp[N] = N;
		swim(N);
	}
	int deleMax()
	{
		int max = elements[pq[1]];
		change(1,N--);
		sink(1);
		return max;
	}

	void output()
	{
		for (int i = 1; i < N; i++)
		{
			//cout << elements[pq[i]]<<" ";
		}
	}

};

inline int* Copy(int a[], int length)
{
	int *b = new int[length];

	for (int i = 0; i < length; i++)
	{
		b[i] = a[i];
	}

	return b;
}

int main()
{
	int a[100], number = 0, mark = 0;

	while (mark >= 0)
	{
		cin >> mark;

		if (mark < 0) break;

		a[number++] = mark;
	}


	int* b = Copy(a, number);
	IndexMaxPQ pq;
	for (int i = 0; i < number; i++)
	{
		pq.Insert(b[i]);
	}
	pq.output();

	for (int i = 0; i < number; i++)
	{
		cout << pq.deleMax() << " ";
	}

	delete(b);

	getchar();
	getchar();

	return 0;
}