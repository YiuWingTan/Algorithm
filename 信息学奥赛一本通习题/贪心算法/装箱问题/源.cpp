
#include<iostream>
#include<vector>
using namespace std;

int a[7];

vector<int> re;

int main()
{
	while (true)
	{
		bool isover = true;
		for (int i = 1; i < 7; i++)
		{
			cin >> a[i];
			if (a[i] != 0) isover = false;
		}
			
		if (isover) break;

		int num = 0;
		for (int i =6 ; i >=1; i--)
		{

			while (a[i] > 0)
			{

				switch (i)
				{
					case 1:
					{
						a[i] -= 36;
						num++;
						break;
					}
					case 2:
					{
						a[i] -= 9;
						if (a[i] < 0) a[1] -= 36 - (a[i] + 9) * 4;
						num++;
						break;
					}
					case 3:
					{
						a[i] -= 4;
						if (a[i] < 0)
						{
							int t = 36,v = 0;
							if (a[i] + 4 == 3) { t -= 27; a[2] -= 1; v = 1; }
							if (a[i] + 4 == 2) { t -= 18; a[2] -= 3; v = 3; }
							if (a[i] + 4 == 1) { t -= 9; a[2] -= 5; v = 5; }

							if (a[2] <= 0)
							{
								a[1] -=t- 4 * (a[2] + v);
							}
						}
						num++;
						break;
					}
					case 4:
					{
						a[i]--;
						a[2] -= 5;
						if (a[2] < 0) a[1] -= 20 - (a[2] + 5) * 4;
						num++;
						break;
					}
					case 5:
					{
						a[i]--;
						a[1] -= 11;
						num++;
						break;
					}
					case 6:
					{
						a[i]--;
						num++;
						break;
					}
				}
				

			}


		}

		re.push_back(num);

	}


	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i]<<endl;
	}

	return 0;
}


