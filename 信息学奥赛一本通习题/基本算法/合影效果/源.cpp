#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct Student
{
	float grade;
	int sex;
} students[50];
char str[50];

bool cmp(Student &i, Student&j)
{

	if (i.sex == 1 && j.sex == 0)  return 0;

	if (i.sex == j.sex&&i.sex == 0 && i.grade > j.grade)return 0;
	
	if (i.sex == j.sex&&i.sex == 1 && i.grade < j.grade)return 0;

	return 1;
}


int main()
{

	int n;

	while (cin >> n)
	{
		
		for (int i = 1; i <= n; i++)
		{
			cin >> str >> students[i].grade;
			if (strcmp(str,"male") == 0)
			{
				students[i].sex = 0;
			}
			else {
				students[i].sex = 1;
			}

			
		}
	
		
		sort(students+1,students+n+1,cmp);

		for (int i = 1; i <= n; i++)
			printf("%.2f ",students[i].grade);
		cout << endl;


	}
	return 0;
}
