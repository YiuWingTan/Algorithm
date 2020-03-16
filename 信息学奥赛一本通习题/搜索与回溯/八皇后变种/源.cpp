
#include<string>
#include<iostream>
using namespace std;

string m[93];
int num = 1;
int r[9],c[9],tr[17],tl[17];
int request[93];

void record()
{
	for (int i = 1; i <= 8; i++)
		m[num] += (r[i] + '0');

	num++;

}

void search(int i)
{
	if (i > 8)
	{
		record();
		return;
	}

	for (int j = 1; j <= 8; j++)
	{

		if (c[j] || tr[i + j] || tl[i - j + 7]) continue;

		r[i] = j;
		c[j] = 1;
		tr[i + j] = 1;
		tl[i - j + 7] = 1;

		search(i+1);

		//r[i] = 0;
		c[j] = 0;
		tr[i + j] = 0;
		tl[i - j + 7] = 0;

	}


}



int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> request[i];
	
	search(1);

	for (int i = 0; i < n; i++)
	{
		cout << m[request[i]]<<endl;
	}



	return 0;
}


