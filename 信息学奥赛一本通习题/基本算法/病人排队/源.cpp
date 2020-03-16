#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Patient
{
	char id[11];
	int age;
	int index;

} patients[102];


bool cmp(Patient&i,Patient&j)
{
	if (i.age < 60 && j.age >= 60) return 0;

	if (i.age >= 60 && j.age >= 60)
	{
		if (i.age < j.age) return 0;
		if (i.age == j.age&&i.index > j.index) return 0;
		return 1;
	}

	if (i.age < 60 && j.age < 60 && i.index>j.index) return 0;
	return 1;
}


int main()
{

	int n;

	while (cin >> n)
	{

		for (int i = 1; i <= n; i++)
		{
			cin >> patients[i].id >> patients[i].age;
			patients[i].index = i;
		}

		sort(patients+1,patients+1+n,cmp);

		for (int i = 1; i <= n; i++)
		{
			cout << patients[i].id << endl;
		}

		cout << endl;
	}


	return 0;
}

