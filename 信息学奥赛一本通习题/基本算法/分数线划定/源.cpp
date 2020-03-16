#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;



struct  Student
{
	int id;
	int grade;
} students[6000];


bool cmp(Student &x, Student&y)
{
	return (x.grade > y.grade) || (x.grade == y.grade&&x.id < y.id);
} 


int main()
{

		int n, m;

		cin >> n >> m;
		for (int i = 1; i <=n; i++)
		{
			cin >> students[i].id >> students[i].grade;
		}

		for (int i = 1; i <=n; i++)
		{
			for (int j = 2; j <=n; j++)
			{
				if (students[j - 1].grade < students[j].grade)
				{
					swap(students[j - 1], students[j]);
				}
				else if (students[j - 1].grade == students[j].grade&&students[j - 1].id > students[j].id)
				{
					swap(students[j - 1], students[j]);
				}
			}
		}
		//sort(students+1,students+n+1,cmp);

		m = floor(m*1.5);
		int target = students[m].grade;
		int count = 0;
		
		for (int i = 1; i <=n; i++)
		{
			if (students[i].grade >= target)
			{
				count++;
			}
			else break;
		}

		cout << target << " " << count<<endl;

		for (int i = 1; i <=count; i++)
		{
			cout << students[i].id << " " << students[i].grade << endl;
		}


		//system("pause");
	return 0;
}




