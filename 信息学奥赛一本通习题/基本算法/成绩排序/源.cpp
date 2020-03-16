#include<iostream>
#include<vector>

using namespace std;

struct student
{
	int grade;
	char id[50];
} students[100];

int main()
{

	int n;


	while (cin >> n)
	{
		
		for (int i = 0; i < n; i++) cin >> students[i].id >> students[i].grade;


		for (int i = 0; i<n ;i++)
		{
			for (int j = 0; j <n-1; j++)
			{

				if (students[j].grade < students[j + 1].grade)
				{
					swap(students[j],students[j+1]);
				}
				else if (students[j].grade == students[j + 1].grade&&strcmp(students[j].id,students[j+1].id)>0)
				{
					swap(students[j], students[j + 1]);
				}
			}
		}

		for (int i = 0; i < n; i++)
			cout << students[i].id << " " << students[i].grade << endl;

	}
	return 0;
}




