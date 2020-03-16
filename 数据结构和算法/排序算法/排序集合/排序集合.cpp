// ���򼯺�.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<iostream>

using namespace std;
//using namespace MergerSortion;

inline void Change(int a[], int i, int j)
{
	int middle = a[i];
	a[i] = a[j];
	a[j] = middle;
}

inline void Output(int *a,int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

//��ֵ����ķ���
inline int* Copy(int a[], int length)
{
	int *b = new int[length];

	for (int i = 0; i < length; i++)
	{
		b[i] = a[i];
	}

	return b;
}

//ѡ������
inline void ChoseSort(int a[],int length)
{
	for (int i = 0; i < length; i++)
	{
		int mark = i;
		for (int j = i; j < length; j++)
		{
			if (a[j] < a[mark])
			{
				mark = j;
			}
		}

		int middle = a[i];
		a[i] = a[mark];
		a[mark] = middle;
	}
}

//��������
inline void InsertSort(int a[], int length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0 && a[j - 1] > a[j]; j--)
		{
			int middle = a[j];

			a[j] = a[j - 1];
			a[j - 1] = middle;
		}
	}
}

//ϣ������
inline void HillSort(int a[],int length)
{
	int h = 1;

	while (h < length / 3)
	{
		h = h * 3 + 1;
	}

	while (h >= 1)
	{

		for (int i = 0; i < length; i += h)
		{
			for (int j = i; j > 0 && a[j - h] > a[j]; j -= h)
			{
				int middle = a[j-h];
				a[j - h] = a[j];
				a[j] = middle;
			}
		}

		h /= 3;
	}
}


//�鲢����,�ݹ��(�Զ�����)
inline void Merger(int a[], int n, int k, int m)
{
	int length = (m - n + 1);
	int* b = new int[length];
	int mark = 0;
	int middle = k+1;
	int i = n;

	for (int j = n; j <= m; j++)
	{
		if (i > k) b[mark++] = a[middle++];
		else if (middle > m) b[mark++] = a[i++];
		else if (a[i] < a[middle]) b[mark++] = a[i++];
		else b[mark++] = a[middle++];
	}

	

	for (int j = 0; j < length; j++)
	{
		a[n++] = b[j];
	}

	delete(b);
}

inline void MergerSort(int a[],int n,int m)
	{
		if (n == m) return;

		int k = (m - n) / 2;

		MergerSort(a,n,n+k);
		MergerSort(a,n+k+1,m);
		Merger(a, n, n+k, m);
		
	}

inline int min(int n, int m)
{
	if (n > m) return m;
	return n;

}

//�鲢�����Ե�����
inline void MergerSort2(int a[],int length)
{
	for (int i = 1; i <= length; i*=2)
	{
		for (int lo = 0; lo < length; lo += i*2)
		{
			Merger(a,lo,lo+i-1,min(length-1,lo+i*2-1));
		}
	}
}

inline int partition(int a[],int lo,int ln)
{
	//for()

	int i = lo;

	int j = ln+1;

	int v = a[lo];

	while (true)
	{
		while (a[++i] < v) if (i >= ln) break;
		while (a[--j] > v) if (j <= lo) break;

		if (i >= j) break;

		Change(a, i, j);
		
	}

	Change(a, lo, j);

	return j;
}
//��������
inline void QuickSort(int a[],int lo,int ln)
{
	if (lo >= ln) return;

	int k = partition(a,lo,ln);

	QuickSort(a,lo,k-1);

	QuickSort(a,k+1,ln);
}
//�����зֿ�������
inline void Quick3Way(int a[] ,int lo ,int hi)
{
	if (lo >= hi) return;

	int gt = hi,lt = lo;
	int i = lo+1;
	int v = a[lo];
	while (i <= gt)
	{
		if (a[i] > v) Change(a,i,gt--);
		else if (a[i] < v) Change(a,i++,lt++);
		else i++;
	}

	Quick3Way(a,lo,lt-1);
	Quick3Way(a,gt+1,hi);
}



int main()
{
	int a[100],number = 0,mark = 0;

	while (mark >= 0)
	{
		cin >> mark;

		if (mark < 0) break;

		a[number++] = mark;
	}

	cout << "ѡ������\n";
	int* b = Copy(a,number);
	ChoseSort(b, number);

	Output(b, number);

	delete(b);

	cout << "��������\n";
	b = Copy(a, number);

	InsertSort(b, number);

	Output(b, number);

	delete(b);


	cout << "ϣ������\n";
	b = Copy(a, number);

	HillSort(b, number);

	Output(b, number);

	delete(b);

	cout << "�鲢����\n";
	b = Copy(a, number);

	MergerSort(b, 0, number - 1);

	Output(b, number);

	delete(b);

	cout << "�鲢����,�Ե�����\n";
	b = Copy(a, number);

	MergerSort2(b, number);

	Output(b, number);

	delete(b);

	cout << "��������\n";
	b = Copy(a, number);

	QuickSort(b, 0, number - 1);

	Output(b, number);

	delete(b);


	cout << "�����зֿ�������\n";
	b = Copy(a, number);

	Quick3Way(b, 0, number - 1);

	Output(b, number);

	delete(b);


	getchar();
	getchar();

    return 0;
}

